#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

struct Vector2
{
	int x;
	int y;
	Vector2() :x(), y() {}
	Vector2(int new_x,int new_y) :x(new_x), y(new_y) {}
};
struct Line
{
	Vector2 anchor;
	float m;
	Line (float line_m,Vector2 line_anchor) :m(line_m), anchor(line_anchor)
	{
	}
};
/*
int main()
{
	int n_data;
	cin >> n_data;
	while (n_data--)
	{
		vector<Line> all_lines;
		vector<Vector2> all_points;
		all_lines.clear();
		all_points.clear();
		int n_points;
		cin >> n_points;
		while (n_points--)
		{
			int x, y;
			cin >> x >> y;
			Vector2 new_point(x, y);
			all_points.push_back(new_point);
		}
		for (int i = 0; i < all_points.size() - 1; i++)
		{
			for (int j = i + 1; j < all_points.size(); j++)
			{
				float new_m;
				if (all_points[j].x == all_points[i].x)
				{
					new_m = INT_MAX;
				}
				else
				{
					new_m = (float)(all_points[j].y - all_points[i].y) / (float)(all_points[j].x - all_points[i].x);
				}

				bool repeat = false;
				
				for (int k = 0; k < all_lines.size(); k++)
				{
					float old_m = all_lines[k].m;
					Vector2 anchor = all_lines[k].anchor;
					float m_with_anchor;
					if (anchor.x == all_points[j].x)
					{
						m_with_anchor = INT_MAX;
					}
					else
					{
						m_with_anchor = (float)(all_points[j].y - anchor.y) / (float)(all_points[j].x - anchor.x);
					}
					if ((new_m == old_m) && (new_m == m_with_anchor))
					{
						repeat = true;
						break;
					}

				}

				if (!repeat)
				{
					Line new_line(new_m, all_points[i]);
					all_lines.push_back(new_line);
				}
			}
		}
		cout << all_lines.size() << endl;

	}
	//system("pause");
	return 0;
}
*/

/*
Sample Input:
2
7 0 0 1 1 2 2 3 3 4 4 6 6 0 3
5 0 0 1 1 1 -1 -1 1 -1 -1
Sample Output:
7
6

*/