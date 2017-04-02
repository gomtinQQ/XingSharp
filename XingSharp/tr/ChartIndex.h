#ifndef _ChartIndex_H_
#define _ChartIndex_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// íƮ��ǥ��������ȸ ( HEADTYPE=B )
#pragma pack( push, 1 )

#define NAME_ChartIndex     "ChartIndex"

// In(*EMPTY*)                    
typedef struct _ChartIndexInBlock
{
    char    indexid             [  10];    // [long  ,   10] ��ǥID                          StartPos 0, Length 10
    char    indexname           [  40];    // [string,   40] ��ǥ��                          StartPos 10, Length 40
    char    indexparam          [  40];    // [string,   40] ��ǥ���Ǽ���                    StartPos 50, Length 40
    char    market              [   1];    // [string,    1] ���屸��                        StartPos 90, Length 1
    char    period              [   1];    // [string,    1] �ֱⱸ��                        StartPos 91, Length 1
    char    shcode              [   8];    // [string,    8] �����ڵ�                        StartPos 92, Length 8
    char    qrycnt              [   4];    // [long  ,    4] ��û�Ǽ�(�ִ� 500��)            StartPos 100, Length 4
    char    ncnt                [   4];    // [long  ,    4] ����(nƽ/n��)                   StartPos 104, Length 4
    char    sdate               [   8];    // [string,    8] ��������                        StartPos 108, Length 8
    char    edate               [   8];    // [string,    8] ��������                        StartPos 116, Length 8
    char    Isamend             [   1];    // [string,    1] �����ְ� �ݿ� ����              StartPos 124, Length 1
    char    Isgab               [   1];    // [string,    1] ������ ����                     StartPos 125, Length 1
    char    IsReal              [   1];    // [string,    1] �ǽð� �����ͼ��� �ڵ���� ���� StartPos 126, Length 1
} ChartIndexInBlock, *LPChartIndexInBlock;
#define NAME_ChartIndexInBlock     "ChartIndexInBlock"

// Out(*EMPTY*)                   
typedef struct _ChartIndexOutBlock
{
    char    indexid             [  10];    // [long  ,   10] ��ǥID                          StartPos 0, Length 10
    char    rec_cnt             [   5];    // [long  ,    5] ���ڵ尹��                      StartPos 10, Length 5
    char    validdata_cnt       [   2];    // [long  ,    2] ��ȿ ������ �÷� ����           StartPos 15, Length 2
} ChartIndexOutBlock, *LPChartIndexOutBlock;
#define NAME_ChartIndexOutBlock     "ChartIndexOutBlock"

// Out(*EMPTY*)                   , occurs
typedef struct _ChartIndexOutBlock1
{
    char    date                [   8];    // [string,    8] ����                            StartPos 0, Length 8
    char    time                [   6];    // [string,    6] �ð�                            StartPos 8, Length 6
    char    open                [  10];    // [float ,   10] �ð�                            StartPos 14, Length 10
    char    high                [  10];    // [float ,   10] ��                            StartPos 24, Length 10
    char    low                 [  10];    // [float ,   10] ����                            StartPos 34, Length 10
    char    close               [  10];    // [float ,   10] ����                            StartPos 44, Length 10
    char    volume              [  12];    // [float ,   12] �ŷ���                          StartPos 54, Length 12
    char    value1              [  10];    // [float ,   10] ��ǥ��1                         StartPos 66, Length 10
    char    value2              [  10];    // [float ,   10] ��ǥ��2                         StartPos 76, Length 10
    char    value3              [  10];    // [float ,   10] ��ǥ��3                         StartPos 86, Length 10
    char    value4              [  10];    // [float ,   10] ��ǥ��4                         StartPos 96, Length 10
    char    value5              [  10];    // [float ,   10] ��ǥ��5                         StartPos 106, Length 10
    char    pos                 [   8];    // [long  ,    8] ��ġ                            StartPos 116, Length 8
} ChartIndexOutBlock1, *LPChartIndexOutBlock1;
#define NAME_ChartIndexOutBlock1     "ChartIndexOutBlock1"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _ChartIndex_H_
