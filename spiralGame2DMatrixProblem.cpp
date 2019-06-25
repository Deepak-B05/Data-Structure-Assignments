/*
*Spiral game problem
*@deepak
*determine total power points collected
*determine coordinates of power points
*/

#include<iostream>
using namespace std;


struct cordinates
{
	int x, y;
};

int** createMatrix(int mtrxSize);
void displayMatrix(int** mtrx, int mtrxSize);
int getTotPowPoints(int** mtrx, int mtrxSize);
struct cordinates* getpowPointCordinats(int** mtrx, int mtrxSize);
void disCordinatsOfPowPoint(cordinates* cordinatsOfPowPoint, int totPowPoints);


int main()
{
	struct cordinates* cordinatsOfPowPoint;
	int mtrxSize, totPowPoints;
	int** mtrx;

	cout << "Enter matrix size : " ;
	cin >> mtrxSize;
	if(0 < mtrxSize && mtrxSize <= 100)
	{
		mtrx = createMatrix(mtrxSize);
		displayMatrix(mtrx, mtrxSize);
		totPowPoints = getTotPowPoints(mtrx, mtrxSize);
		cout << "\nTotal Power Points collected : " << totPowPoints << endl;
		cordinatsOfPowPoint = getpowPointCordinats(mtrx, mtrxSize);
		disCordinatsOfPowPoint(cordinatsOfPowPoint, totPowPoints);
	}

	return 0;
}

//to create matrix dynamically
int** createMatrix(int mtrxSize)
{
	int row, col, rit, left, top, bot, num = 1;

	int** mtrx = new int*[mtrxSize];
	for(int count = 0; count < mtrxSize; count++)
   {
		mtrx[count] = new int[mtrxSize];
   }

	for(row = 0, col = 0; row < mtrxSize; row++, col++)
	{
		for(rit = row; rit < mtrxSize; rit++)
		{
			mtrx[row][rit] = num;
			num++;
		}
		for(bot = row+1; bot < mtrxSize-1; bot++)
		{
			mtrx[bot][mtrxSize-1] = num;
			num++;
		}
		for(left = mtrxSize-1; left > row; left--)
		{
			mtrx[mtrxSize-1][left] = num;
			num++;
		}
		for(top = mtrxSize-1; top > row; top--)
		{
			mtrx[top][col] = num;
			num++;
		}
		mtrxSize--;
	}

	return mtrx;
}

//to display created matrix
void displayMatrix(int** mtrx, int mtrxSize)
{
	int row, col;

	for(row = 0; row < mtrxSize; row++)
	{
		for(col = 0; col < mtrxSize; col++)
		{
			cout << mtrx[row][col] << "\t";
		}
		cout << endl;
	}
}

//To determine total collected power points
int getTotPowPoints(int** mtrx, int mtrxSize)
{
	int totPowPoints = 0, row, col,  rit, left, top, bot;

	for(row = 0, col = 0; row < mtrxSize; row++, col++)
	{
		for(rit = row; rit < mtrxSize; rit++)
		{
			if(1 == mtrx[row][rit])
			{
				totPowPoints++;
			}
			if(0 == mtrx[row][rit]%11)
			{
				totPowPoints++;
			}
		}
		for(bot = row+1; bot < mtrxSize-1; bot++)
		{
			if(0 == mtrx[bot][mtrxSize-1])
			{
				totPowPoints++;
			}
		}
		for(left = mtrxSize-1; left > row; left--)
		{
			if(0 == mtrx[mtrxSize-1][left]%11)
			{
				totPowPoints++;
			}
		}
		for(top = mtrxSize-1; top > row; top--)
		{
			if(0 == mtrx[top][col]%11)
			{
				totPowPoints++;
			}
		}
		mtrxSize--;
	}

	return totPowPoints;
}

//to determine cordinates of collected power points
struct cordinates* getpowPointCordinats(int** mtrx, int mtrxSize)
{
	int row, col, rit, left, top, bot, count = 0;
	cordinates* powPointCordinats = new cordinates[mtrxSize/11+1];

	for(row = 0, col = 0; row < mtrxSize; row++, col++)
	{
		for(rit = row; rit < mtrxSize; rit++)
		{
			if(1 == mtrx[row][rit])
			{
				powPointCordinats[count].x = row;
				powPointCordinats[count].y = rit;
				count++;
			}
			if(0 == mtrx[row][rit]%11)
			{
				powPointCordinats[count].x = row;
				powPointCordinats[count].y = rit;
				count++;
			}
		}
		for(bot = row+1; bot < mtrxSize-1; bot++)
		{
			if(0 == mtrx[bot][mtrxSize-1])
			{
				powPointCordinats[count].x = bot;
				powPointCordinats[count].y = mtrxSize-1;
				count++;
			}
		}
		for(left = mtrxSize-1; left > row; left--)
		{
			if(0 == mtrx[mtrxSize-1][left]%11)
			{
				powPointCordinats[count].x = mtrxSize-1;
				powPointCordinats[count].y = left;
				count++;
			}
		}
		for(top = mtrxSize-1; top > row; top--)
		{
			if(0 == mtrx[top][col]%11)
			{
				powPointCordinats[count].x = top;
				powPointCordinats[count].y = col;
				count++;
			}
		}
		mtrxSize--;
	}

	return powPointCordinats;
}

//To display cordinates of collected power point
void disCordinatsOfPowPoint(cordinates* cordinatsOfPowPoint, int totPowPoints)
{
	for(int count = 0; count < totPowPoints; count++)
	{
		cout << "(" << cordinatsOfPowPoint[count].x << "," ;
		cout << cordinatsOfPowPoint[count].y << ")\n";
	}
}
