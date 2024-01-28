#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

class Timer {
private:
    chrono::steady_clock::time_point start_time;
    chrono::steady_clock::time_point pause_start_time;
    bool paused;
    chrono::milliseconds total_paused_time;

public:
    Timer() : paused(false), total_paused_time(0) {}

    void start() {
        if (!paused) {
            start_time = chrono::steady_clock::now();
            pause_start_time = chrono::steady_clock::time_point();
            total_paused_time = chrono::milliseconds(0);
        } else {
            cout << "Timer is already running." << endl;
        }
    }

    void stop() {
        if (!paused) {
            auto end_time = chrono::steady_clock::now();
            chrono::milliseconds elapsed_time = chrono::duration_cast<chrono::milliseconds>(end_time - start_time - total_paused_time);
            cout << "Elapsed Time: " << elapsed_time.count() / 1000.0 << " seconds" << endl;
            start_time = chrono::steady_clock::time_point();
            pause_start_time = chrono::steady_clock::time_point();
            total_paused_time = chrono::milliseconds(0);
        } else {
            cout << "Timer is paused. Please resume before stopping." << endl;
        }
    }

    void pause() {
        if (!paused) {
            pause_start_time = chrono::steady_clock::now();
            paused = true;
        } else {
            cout << "Timer is already paused." << endl;
        }
    }

    void resume() {
        if (paused) {
            auto pause_end_time = chrono::steady_clock::now();
            total_paused_time += chrono::duration_cast<chrono::milliseconds>(pause_end_time - pause_start_time);
            paused = false;
            pause_start_time = chrono::steady_clock::time_point();
        } else {
            cout << "Timer is not paused." << endl;
        }
    }

    void printElapsedTime() const {
        if (start_time != chrono::steady_clock::time_point()) {
            auto current_time = chrono::steady_clock::now();
            chrono::milliseconds elapsed_time = chrono::duration_cast<chrono::milliseconds>(current_time - start_time - total_paused_time);
            cout << "Time Passed: " << elapsed_time.count() / 1000.0 << " seconds" << endl;
        } else {
            cout << "Timer has not been started." << endl;
        }
    }
};

int main() {
    Timer timer;

    timer.start();
    this_thread::sleep_for(chrono::seconds(2));
    timer.printElapsedTime();
    timer.pause();
    this_thread::sleep_for(chrono::seconds(1));
    timer.resume();
    this_thread::sleep_for(chrono::seconds(2));
    timer.printElapsedTime();
    timer.stop();

    return 0;
}


   

