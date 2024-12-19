#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
int currentThread = 1;

// スレッド関数
void printThread(int id) {
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, [id]() { return currentThread == id; });
    std::cout << "thread " << id << std::endl;
    currentThread++;
    cv.notify_all();
}

int main() {
    // スレッドの作成
    std::thread t1(printThread, 1);
    std::thread t2(printThread, 2);
    std::thread t3(printThread, 3);

    // スレッドの終了待ち
    t1.join();
    t2.join();
    t3.join();

    return 0;
}
