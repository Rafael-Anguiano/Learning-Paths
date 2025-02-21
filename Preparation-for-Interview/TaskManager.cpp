#include <functional>

class TaskManager {
    set<pair<int, int>, greater<pair<int, int>> > tasks;
    unordered_map<int, pair<int,int>> taskUser;
public:
    TaskManager(vector<vector<int>>& tasks) {
        for (vector<int> & v : tasks) {
            this->add(v[0], v[1], v[2]);
        }
    }
    
    void add(int userId, int taskId, int priority) {
        this->tasks.insert(pair<int,int>(priority, taskId));
        this->taskUser[taskId] = pair<int, int>(userId, priority);
    }
    
    void edit(int taskId, int newPriority) {
        pair<int,int> p = this->taskUser[taskId];
        this->rmv(taskId);
        this->add(p.first, taskId, newPriority);
    }
    
    void rmv(int taskId) {
        pair<int,int> p = this->taskUser[taskId];
        this->taskUser.erase(taskId);
        p.first = p.second;
        p.second = taskId;
        this->tasks.erase(p);
    }
    
    int execTop() {
        if (this->tasks.empty()) return -1; 
        pair<int,int> p = * this->tasks.begin();
        this->tasks.erase(p);
        int user = this->taskUser[p.second].first;
        this->taskUser.erase(p.second);
        return user;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */
