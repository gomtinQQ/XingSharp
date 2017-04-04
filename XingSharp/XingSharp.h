#pragma once

using namespace System;
using namespace System::Runtime::InteropServices;

namespace XingSharp
{
	class ApiWrapper;

	public enum class ChartPeriod : char
	{
		Tick = 0,		// ƽ
		Minute = 1,		// ��
		Daily = 2,		// ��
		Weekly = 3,		// ��
		Monthly = 4,	// ��
	};

	public enum class ChartMarketType : char
	{
		Stock = 1,			// �ֽ�
		Industry = 2,		// ����
		FutureOption = 5,	// �����ɼ�
	};

	public enum class ChartIndexType : char
	{
		PriceMoveAverage,		// �����̵����
		EstrangementRatio,		// �̰ݵ�
		AverageTrueRange,
		MACD,
		RSI,
		OBV,
		Momentum,
		SonarMomentum,
		PriceROC,
		VolumeROC
	};

	public enum class SignAgainstYesterday : char
	{
		UpperLimit,
		Up,
		NoChange,
		Down,
		LowerLimit,

		InvalidValue
	};

	public ref class Xt2101
	{
	public:
		String^ HangulName;	// �ѱ۸�
		SignAgainstYesterday Sign; // ���ϴ�񱸺�

		String^ LastMonth;	// ������
		int JanDateCnt;	// �ܿ���

		String^ Price;	// ���簡
		String^ Change;	// ���ϴ��
		String^ JnilClose;	// ��������
		String^ UpLmtPrice;	// ���Ѱ�
		String^ DnLmtPrice;	// ���Ѱ�
		String^ RecPrice;	// ���ذ�
		String^ KospiJisu;	// KOSPI200����
		// TODO: more fields
	};

	public ref class XChartIndexItem
	{
	public:
		String^ Day;		// ����
		String^ Time;		// �ð�
		String^ Open;		// �ð�
		String^ High;		// ��
		String^ Low;		// ����
		String^ Close;		// ����
		String^ Volume;		// �ŷ���

		// Value�� ������ ValueNames ����
		array<String^>^ IndexValues;
	};

	public ref class XChartIndex
	{
	public:
		ChartIndexType Type;
		array<String^>^ ValueNames;
		array<XChartIndexItem^>^ Items;
		bool HasError;	// ���ǻ� API ����� �ʵ��,�÷����� �޶��� �� �ִ�.
	};

	public interface class IXingApiListener
	{
		void Xing_Connect(bool success, String^ errorMsg);
		void Xing_Login(bool success, String^ errorCode, String^ errorMsg);

		void Xing_T2101(Xt2101^ t2101);
		void Xing_ChartIndex(XChartIndex^ chart);
	};

	public ref class XingApi
	{
	public:
		XingApi(IXingApiListener^ pListener);
		
		bool Create(String^ apiDir, [Out]String^% errorMsgOut); // errorMsgOut is valid only if Create() failed
		void Destroy();

		bool IsConnected();

		bool Connect(String^ address, int port);
		bool Login(String^ userId, String^ userPw, String^ certPw);
		//bool Logout();

		void SetQueryRowCount(int cnt);
		bool Request_T2101(String^ shcode);	// ���簡 ��ȸ
		bool Request_ChartIndex(String^ shcode, String^ endDate, ChartMarketType marketType, ChartIndexType indexType, ChartPeriod period);

		void OnConnect(bool success, LPCTSTR pszMsg);
		void OnLoginSuccess();
		void OnLoginFailed(LPCSTR pszCode, LPCTSTR pszMsg);

		IXingApiListener^ m_pListener;

	private:
		ApiWrapper* m_pApiWrapper;
	};
}
