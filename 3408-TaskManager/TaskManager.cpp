#include <iostream>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

class TaskManager
{
  public:
    TaskManager(vector<vector<int>> &tasks)
    {
        for (const auto &task : tasks)
        {
            Task t;
            t.userId = task[0];
            t.id = task[1];
            t.priority = task[2];
            tasks_.push(t);

            latestProiority_[t.id] = t.priority;
            taskIdAndUser_[t.id] = t.userId;
        }
    }

    void add(int userId, int taskId, int priority)
    {
        Task t{taskId, userId, priority};
        tasks_.push(t);

        latestProiority_[t.id] = t.priority;
        taskIdAndUser_[t.id] = t.userId;
    }

    void edit(int taskId, int newPriority)
    {
        latestProiority_[taskId] = newPriority;
        Task t{taskId, taskIdAndUser_[taskId], newPriority};
        tasks_.push(t);
    }

    void rmv(int taskId)
    {
        auto latestProiority_it = latestProiority_.find(taskId);
        latestProiority_.erase(latestProiority_it);

        auto taskIdAndUser_it = taskIdAndUser_.find(taskId);
        taskIdAndUser_.erase(taskIdAndUser_it);
    }

    int execTop()
    {
        while (!tasks_.empty())
        {
            auto t = tasks_.top();
            tasks_.pop();

            if (latestProiority_.find(t.id) == latestProiority_.end())
                continue;
            if (latestProiority_[t.id] != t.priority)
                continue;
            if (taskIdAndUser_[t.id] != t.userId)
                continue;

            rmv(t.id);
            return t.userId;
        }

        return -1;
    }

  private:
    struct Task
    {
        int id;
        int userId;
        int priority;

        bool operator<(const Task &other) const
        {
            if (this->priority < other.priority)
                return true;
            if (this->priority == other.priority && this->id < other.id)
                return true;
            return false;
        }
    };

    priority_queue<Task> tasks_;
    unordered_map<int, int> latestProiority_;
    unordered_map<int, int> taskIdAndUser_;
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */