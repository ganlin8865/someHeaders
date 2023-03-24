//hello!
#include "littletools.h"
#include "windowstools.h"

using namespace ltools::random;
using namespace ltools::sort;
using namespace ltools::stack;
using namespace wintools::consle;
using namespace wintools::msgbox;
using namespace wintools::playtone;
using namespace wintools::window;

int main() 
{
	MessageBox(nullptr, L"Hello World!", L"Sample Message Box", MB_OK);
	HWND hwnd = FindWindow(nullptr, L"Sample Message Box");
	if (hwnd != nullptr) 
	{
		std::srand(std::time(nullptr));
		int x = std::rand() % 800;
		int y = std::rand() % 600;
		MoveWindow(hwnd, x, y, 300, 150, TRUE);
	}
	return 0;
}