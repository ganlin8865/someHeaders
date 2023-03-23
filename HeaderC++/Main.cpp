#include <iostream>
#include <boost/timer/timer.hpp>
using namespace std;
int n, a, b, c, t, ans;
int main()
{
	cin >> n >> a >> b;
	for (int i = 1; i <= n; i++)
	{
		cin >> t;
		if (t == 1)
		{
			if (a)
			{
				a--;
			}
			else if (b)
			{
				b--;
				c++;
			}
			else if (c)
			{
				c--;
			}
			else
			{
				ans += t;
			}
		}
		else if (b)
		{
			b--;
		}
		else
		{
			ans += t;
		}
	}
	cout << ans << endl;
}