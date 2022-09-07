#include <iostream>
#include <thread>
#include <condition_variable>
#include <mutex>

// 条件变量wait时, 需要给其添加条件判断
class ConditionVariable
{
private:
    int data_{0};
    bool isWrite_{false};
    std::mutex dataMutex_;
    std::condition_variable dataCv_;

public:
    void ReadThread()
    {
        std::unique_lock<std::mutex> lock(dataMutex_);
        
        //防止虚假唤起
        while (!isWrite_)
        {
            dataCv_.wait(lock);
        }
        // 或者：dataCv_.wait(lock, [this]{return this->isWrite_;});
        
        // 获取已写数据
        int temp = data_;
    }

    void WriteThread()
    {
        std::unique_lock<std::mutex> lock(dataMutex_);

        // 写数据
        data_ = 99;
        // 修改wait条件
        isWrite_ = true;
        // 通知
        dataCv_.notify_all();
    }
};
