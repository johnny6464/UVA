#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct Robot
{
	int pos_x = 0;
	int pos_y = 0;
	char dir;
};

int main()
{
	int row = 0, col = 0;
	cin >> row >> col;

	vector<vector<bool>> ground;
	for (int i = 0; i <= row; i++)
	{
		vector<bool> v(col + 1, false);
		ground.push_back(v);
	}

	int pos_x = 0, pos_y = 0;
	char dir;
	while (cin >> pos_x >> pos_y >> dir)
	{
		Robot robot;
		robot.pos_x = pos_x;
		robot.pos_y = pos_y;
		robot.dir = dir;
		bool loss = false;

		string movement;
		cin >> movement;

		for (int i = 0; i < movement.size(); i++)
		{
			if (loss)
			{
				break;
			}
			switch (movement[i])
			{
			case 'L':
				if (robot.dir == 'N')
				{
					robot.dir = 'W';
				}
				else if (robot.dir == 'E')
				{
					robot.dir = 'N';
				}
				else if (robot.dir == 'S')
				{
					robot.dir = 'E';
				}
				else if (robot.dir == 'W')
				{
					robot.dir = 'S';
				}
				break;
			case 'R':
				if (robot.dir == 'N')
				{
					robot.dir = 'E';
				}
				else if (robot.dir == 'E')
				{
					robot.dir = 'S';
				}
				else if (robot.dir == 'S')
				{
					robot.dir = 'W';
				}
				else if (robot.dir == 'W')
				{
					robot.dir = 'N';
				}
				break;
			case 'F':
				if (robot.dir == 'N')
				{
					if (robot.pos_y == col)
					{
						if (!ground[robot.pos_x][robot.pos_y])
						{
							loss = true;
							ground[robot.pos_x][robot.pos_y] = 1;
						}
					}
					else
					{
						robot.pos_y++;
					}
				}
				else if (robot.dir == 'E')
				{
					if (robot.pos_x == row)
					{
						if (!ground[robot.pos_x][robot.pos_y])
						{
							loss = true;
							ground[robot.pos_x][robot.pos_y] = 1;
						}
					}
					else
					{
						robot.pos_x++;
					}
				}
				else if (robot.dir == 'S')
				{
					if (robot.pos_y == 0)
					{
						if (!ground[robot.pos_x][robot.pos_y])
						{
							loss = true;
							ground[robot.pos_x][robot.pos_y] = 1;
						}
					}
					else
					{
						robot.pos_y--;
					}
				}
				else if (robot.dir == 'W')
				{	
					if (robot.pos_x == 0)
					{
						if (!ground[robot.pos_x][robot.pos_y])
						{
							loss = true;
							ground[robot.pos_x][robot.pos_y] = 1;
						}
					}
					else
					{
						robot.pos_x--;
					}
				}
				break;
			default:
				break;
			}
		}

		if (!loss)
		{
			cout << robot.pos_x << " " << robot.pos_y << " " << robot.dir << endl;
		}
		else
		{
			cout << robot.pos_x << " " << robot.pos_y << " " << robot.dir << " LOST" << endl;
		}
		
	}

	system("pause");
	return 0;
}