/**
*@deepak
*last compiled on 20/06/2019
*/

/*
* To determine the closest sub square matrix
*/

#include<iostream>
#include<string.h>
using namespace std;

struct inpString
{
    char name[500];
    int result;
};

//to determine the closest square matrix
int getClosestSqurMtrxSize(char* userStr, char mtrx[][500], int MtrxSize)
{
    int row = 0, col = 0, closestIndex = -1;
    int freq[26] = {0};

    for(int strC = 0; userStr[strC] != '\0'; strC++)
    {
        freq[userStr[strC]-97]++;
    }
    for(row = 0, col = 0; row < MtrxSize; row++, col++)
    {
        if( freq[mtrx[row][col]-97] > 0)
        {
            closestIndex = row;
            freq[mtrx[row][col]-97]--;
        }

        int count = 0;

        for(count = row-1; count >= 0; count--)
        {
            if(freq[mtrx[row][count]-97] > 0)
            {
                closestIndex = row;
                freq[mtrx[row][count]-97]--;
            }
            if(freq[mtrx[count][col]-97] > 0)
            {
                closestIndex = col;
                freq[mtrx[count][col]-97]--;
            }
        }

    }


    return closestIndex+1;
}



int main() {
    
    int noOfTestCase = 0, mtrxSize = 0, strCount = 0;
    char userStr[500];
    char matrx[500][500];

    cout << "Enter the no. of test cases" << endl;
    cin >> noOfTestCase;

    if( 1 <= noOfTestCase && noOfTestCase <= 5)
    {
        for(int count = 1; count <= noOfTestCase; count++)
        {
            cout << "\n....TEST CASE " << count << " INPUT...." << endl;
            cout << "Enter the size of matrix : " << endl;
            cin >> mtrxSize;
            if( 1 <= mtrxSize && mtrxSize <= 500)
            {
                cout << "Enter the Strings (low case)" << endl;
                for(int row = 0; row < mtrxSize; row++)
                {
                    for(int col = 0; col < mtrxSize; col++)
                    {
                        cin >> matrx[row][col];
                    }
                }

                cout << "Enter count of strings to be searched : " << endl;
                cin >> strCount;
                //
                if(1 <= strCount && strCount <= 25000)
                {
                    if(strCount > 1)
                    {
                        cout << "Enter " << strCount << " Strings " << endl;
                    }
                    else
                    {
                        cout << "Enter " << strCount << " String " << endl;
                    }
                    struct inpString* strRecord = new struct inpString[strCount];
                    for(int sCount = 0; sCount < strCount; sCount++)
                    {
                        cin >> strRecord[sCount].name;
                        strRecord[sCount].result = getClosestSqurMtrxSize(strRecord[sCount].name, matrx, mtrxSize);
                    }
                    cout << "\n....TEST CASE " << count << " OUTPUT...." << endl;
                    for(int sCount = 0; sCount < strCount; sCount++)
                    {
                        cout << "For string " << sCount+1 << " square-matrix closest from (1, 1) is ";                                           cout << strRecord[sCount].result << " " << strRecord[sCount].result << endl;
                    }
                }
            }
        }
    }

    return 0;
}

