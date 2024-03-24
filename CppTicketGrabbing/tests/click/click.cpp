#include <windows.h>
 
void left_click() {
    // 模拟鼠标左键点击
    mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
}
 
int main() {
    // 在屏幕上模拟点击
    left_click();
    return 0;
}