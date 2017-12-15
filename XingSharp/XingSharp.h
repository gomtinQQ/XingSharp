#pragma once

using namespace System;
using namespace System::Runtime::InteropServices;

namespace XingSharp
{
	class ApiWrapper;

	public enum class ChartPeriodType : char
	{
		Tick = 0,		// ƽ
		Minute = 1,		// ��
		Daily = 2,		// ��
		Weekly = 3,		// ��
		Monthly = 4,	// ��
		//Yearly = 5,		// ��
	};

	public enum class ChartMarketType : char
	{
		Stock = 1,			// �ֽ�
		Industry = 2,		// ����
		FutureOption = 5,	// �����ɼ�
	};

	public ref class ChartIndexName
	{
	public:
		literal String^ PriceMoveAverage = "���� �̵����";
		literal String^ Disparity = "�̰ݵ�";
		literal String^ AverageTrueRange = "Average True Range";
		literal String^ MACD = "MACD";
		literal String^ RSI = "RSI";
		literal String^ OBV = "OBV";
		literal String^ Momentum = "Momentum";
		literal String^ SonarMomentum = "Sonar Momentum";
		literal String^ PriceROC = "Price ROC";
		literal String^ VolumeROC = "Volume ROC";
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

	public ref class XTradeAmount
	{
	public:
		String^ Sell;		// �ŵ�
		String^ Buy;		// �ż�
		String^ NetBuy;		// ���ż�
		String^ Rate;		// ����
	};

	public ref class XTraders
	{
	public:
		XTradeAmount^ Individual;	// ����
		XTradeAmount^ Foreigner;	// �ܱ���
		XTradeAmount^ Institute;	// �����
		XTradeAmount^ StockFirm;	// ����
		XTradeAmount^ InvestTrust;	// ����
		XTradeAmount^ Bank;			// ����
		XTradeAmount^ Insurance;	// ����
		XTradeAmount^ InvestBank;	// ����
		XTradeAmount^ Fund;			// ���
		XTradeAmount^ Government;	// ����
		XTradeAmount^ PrivateEquity;// ����ݵ�
		XTradeAmount^ Etc;			// ��Ÿ
	};

	public ref class Xt1601
	{
	public:
		XTraders^ Kospi;
		XTraders^ Kosdaq;
		XTraders^ Future;
		XTraders^ CallOpt;
		XTraders^ PutOpt;
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

	public ref class Xt1633Item
	{
	public:
		String^ Date;
		String^ Jisu;				// KOSPI200 ����
		String^ Sign;				// ��񱸺� (1:����, 2:���, 	3:����, 4:����, 5:�϶�)
		String^ Change;				// ���
		String^ TotalNetBuy;		// ��ü ���ż�
		String^ TotalBuy;			// ��ü �ż�
		String^ TotalSell;			// ��ü �ŵ�
		String^ ArbitrageNetBuy;	// ���� ���ż�
		String^ ArbitrageBuy;		// ���� �ż�
		String^ ArbitrageSell;		// ���� �ŵ�
		String^ NoArbitrageNetBuy;	// ������ ���ż�
		String^ NoArbitrageBuy;		// ������ �ż�
		String^ NorbitrageSell;		// ������ �ŵ�
		String^ Volume;				// �ŷ���
	};

	public ref class Xt1633
	{
	public:
		String^ ContinueDate;	// ������ȸ�� ��¥ (���� ��� ����)
		array<Xt1633Item^>^ Items;
	};

	public ref class XtFC0
	{
	public:
		String^ CheTime;	// ü��ð�
		SignAgainstYesterday Sign; // ���ϴ�񱸺�
		String^ Change;		// ���ϴ��
		String^ DRate;		// �����
		String^ Price;		// ���簡
		String^ Open;		// �ð�
		String^ High;		// ��
		String^ Low;		// ����
		String^ CGubun;		// ü�ᱸ��
		String^ CVolume;	// ü�ᷮ
		String^ Volume;		// �����ŷ���
		String^ Value;		// �����ŷ����
		String^ MdVolume;	// �ŵ�����ü�ᷮ
		String^ MdCheCnt;	// �ŵ�����ü��Ǽ�
		String^ MsVolume;	// �ż�����ü�ᷮ
		String^ MsCheCnt;	// �ż�����ü��Ǽ�
		String^ CPower;		// ü�ᰭ��
		String^ OfferHo1;	// �ŵ�ȣ��1
		String^ BidHo1;		// �ż�ȣ��1
		String^ OpenYak;	// �̰�����������
		String^ K200Jisu;	// KOSPI200����
		String^ TheoryPrice;// �̷а�
		String^ Kasis;		// ������
		String^ Sbasis;		// ����BASIS
		String^ Ibasis;		// �̷�BASIS
		String^ OpenYakCha;	// �̰�����������
		String^ JGubun;		// ������
		String^ JnilVolume;	// ���ϵ��ð���ŷ���
		String^ FutCode;	// �����ڵ�
	};

	// Output of ChartIndex
	public ref class XChartIndex
	{
	public:
		String^ UserKey;
		int UserParam;

		array<String^>^ ValueNames;	// names of Items.IndexValues
		array<XChartIndexItem^>^ Items;
		bool HasError;	// ���ǻ� API ����� �ʵ��,�÷����� �޶��� �� �ִ�.
	};

	// Input for ChartIndex
	public ref class XChartIndexParam
	{
	public:
		ChartMarketType Market;
		ChartPeriodType Period;
		String^ IndexName;
		String^ ShCode;
		String^ EndDate;	// ex: 20161231
		int QueryCount;		// max 500 (0 for default)
		int TicksOrMinutes; // N-ticks, or N-minutes (0 for default) 
		bool FixGap;
		bool AmendPrice;
		bool RegisterReal;

		// two user variables for any purpose
		String^ UserKey;
		int UserParam;
	};

	public interface class IXingApiListener
	{
		void Xing_Connect(bool success, String^ errorMsg);
		void Xing_Login(bool success, String^ errorCode, String^ errorMsg);
		void Xing_ErrorMessage(String^ errorMsg);

		void Xing_FC0(XtFC0^ fc0);
		void Xing_T2101(Xt2101^ t2101);
		void Xing_T1601(Xt1601^ t1601);
		void Xing_T1633(Xt1633^ t1633);		
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

		bool Advise_FC0(String^ futcode);
		bool Unadvise_FC0(String^ futcode);

		bool Advise_JIF();
		bool Unadvise_JIF();

		void SetQueryRowCount(int cnt);
		bool Request_T2101(String^ shcode);	// ���簡 ��ȸ
		bool Request_T1601(bool forMoney);	// �����ں� ���� (true=�ݾ�, false=����)
		bool Request_T1633(bool forMoney);	// �Ⱓ�� ���α׷� �Ÿ����� (�ŷ��� ���ϱ��� �Ѵ�ġ �Ϻ��� ��ȸ)
		bool Request_ChartIndex(XChartIndexParam^ param);

		void OnConnect(bool success, LPCTSTR pszMsg);
		void OnLoginSuccess();
		void OnLoginFailed(LPCSTR pszCode, LPCTSTR pszMsg);
		void OnErrorMessage(LPCWSTR pszMsg);

		IXingApiListener^ m_pListener;

	private:
		ApiWrapper* m_pApiWrapper;
	};
}
