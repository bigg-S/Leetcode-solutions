#include <iostream>
#include <deque>
#include <vector>

class Solution
{
private:
	std::vector<std::vector<int>> board;
	int rows = board.size();
	int cols = board[0].size();
	std::vector<std::vector<int>> dir = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

	bool** visited = new bool* [rows];
	for (int i = 0;i < rows; i++)
	{
		bool visited[i] = new visited[cols];
		for (int j = 0; j < cols; j++)
		{
			visited[i][j] = false;
		}
	}
public:

	int countBattleShip(std::vector<std::vector<char>>& board)
	{
		int count = 0;

		for (int r = 0; r < board.size(); r++)
		{
			for (int c = 0; c < board[0].size(); c++)
			{
				if (board[r][c] == 'X' && !visited[r][c])
				{
					bfs(r, c);
					count++;
				}
			}
		}
		return count;
	}

	void bfs(int r, int c)
	{
		std::deque<std::pair<int, int>> que;
		int rows = board.size();
		int cols = board[0].size();

		que.push_back(std::make_pair(r, c));

		while (!que.empty())
		{
			std::pair<int, int> my_pair = que.front();
			int m = my_pair.first;
			int n = my_pair.second;
			que.pop_front();

			for (int k = 0; k < dir.size(); k++)
			{
				int dr = m + dir[k][0];
				int dc = n + dir[k][1];
				if (!visited[dr][dc] && dr >= 0 && dr < board.size() && dc >= 0 && dc < board[0].size() && board[dr][dc] == 'X')
				{
					visited[dr][dc] = true;
					que.push_back(std::make_pair(dr, dc));
				}
			}
		}
		
		return;
	}

};

int main()
{
	std::vector<std::vector<int>> board = { {'X', '.', 'X'} };
	Solution s;
	std::cout << s.countBattleShip(board);
	return 0;
}