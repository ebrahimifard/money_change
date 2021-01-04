
#include <iostream>
#include <conio.h>
#include <vector>
using namespace std;

static vector<int> forFirstCoin;
static vector<int> forSecondCoin;
static vector<int> forThirdCoin;

void devider( int n )
{
	int firstCoin=2,secondCoin=5,thirdCoin=10;
	static int step=1;

	if( step > 7 )
		return ;
	else
	{
		if( step==1 )
		{
			//cout << endl << "----------------------";
			//cout << endl << "We are in step 1";
			if( n%firstCoin == 0 )
			{
				forFirstCoin.push_back( n/firstCoin ) ;
				forSecondCoin.push_back( 0 ) ;
				forThirdCoin.push_back( 0 ) ;
				//cout << endl << n/firstCoin << "   TwoCoins";
			}
			
			step++ ;
			devider(n);
		}

		if( step==2 )
		{
			//cout << endl << "----------------------";
			//cout << endl << "We are in step 2";
			if( n%secondCoin == 0 )
			{
				forFirstCoin.push_back( 0 ) ;
				forSecondCoin.push_back( n/secondCoin ) ;
				forThirdCoin.push_back( 0 ) ;
				//cout << endl << n/secondCoin << "   FiveCoins";
			}
			step++ ;
			devider(n);
		}

		if( step==3 )
		{
			//cout << endl << "----------------------";
			//cout << endl << "We are in step 3";
			if( n%thirdCoin == 0 )
			{
				forFirstCoin.push_back( 0 ) ;
				forSecondCoin.push_back( 0 ) ;
				forThirdCoin.push_back( n/thirdCoin ) ;
				//cout << endl << n/thirdCoin << "   TenCoins";
			}
			step++ ;
			devider(n);
		}
		if( step==4 )
		{
			//cout << endl << "----------------------";
			//cout << endl << "We are in step 4";
			for( int a=1 ; a<n ; a++ )
			{
				for( int b=1 ; b<n ; b++ )
				{
					if( 5*a + 2*b == n )
					{
						forFirstCoin.push_back( b ) ;
						forSecondCoin.push_back( a ) ;
						forThirdCoin.push_back( 0 ) ;
						//cout << endl << a << "   FiveCoins";
						//cout << endl << b << "   TwoCoins";
					}
				}
			}
			step++ ;
			devider(n) ;
		}

		if( step==5 )
		{
			//cout << endl << "----------------------";
			//cout << endl << "We are in step 5";
			for( int c=1 ; c<n ; c++ )
			{
				for( int d=1 ; d<n ; d++ )
				{
					if( 10*c + 2*d == n )
					{
						forFirstCoin.push_back( d ) ;
						forSecondCoin.push_back( 0 ) ;
						forThirdCoin.push_back( c ) ;
						//cout << endl << c << "   TenCoins";
						//cout << endl << d << "   TwoCoins";
					}
				}
			}
			step++ ;
			devider(n) ;

		}
		if( step==6 )
		{
			//cout << endl << "----------------------";
			//cout << endl << "We are in step 6";
			for( int e=1 ; e<n ; e++ )
			{
				for( int f=1 ; f<n ; f++ )
				{
					if( 5*e + 10*f == n )
					{
						forFirstCoin.push_back( 0 ) ;
						forSecondCoin.push_back( e ) ;
						forThirdCoin.push_back( f ) ;
						//cout << endl << e << "   FiveCoins";
						//cout << endl << f << "   TenCoins";
					}
				}
			}
			step++ ;
			devider(n) ;

		}
		if( step==7 )
		{
			//cout << endl << "----------------------";
			//cout << endl << "We are in step 7";
			for( int g=1 ; g<n ; g++ )
			{
				for( int h=1 ; h<n ; h++ )
				{
					for( int k=1 ; k<n ; k++ )
					{
						if( 10*g + 5*h + 2*k == n )
						{
							forFirstCoin.push_back( k ) ;
							forSecondCoin.push_back( h ) ;
							forThirdCoin.push_back( g ) ;
							//cout << endl << g << "   TenCoins";
							//cout << endl << h << "   FiveCoins";
							//cout << endl << k << "   TwoCoins";
						}
					}
				}
			}
			step++ ;
			devider(n) ;

		}


	}

}


int main()
{

	int n ;
	cin >> n ;
	devider( n ) ;
	cout << endl << "\t" << "2 Cents" << "\t" << "5 Cents" << "\t" << "10 Cents" ;
	for( int i=0 ; i<forFirstCoin.size() ; i++ )
	{
		cout << endl << "\t  " << forFirstCoin[i] << "\t  " << forSecondCoin[i] << "\t  " << forThirdCoin[i]  ;
	}
	getch();
	return 0;
}