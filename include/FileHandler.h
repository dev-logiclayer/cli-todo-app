#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include "TaskManager.h"
#include <string>

class FileHandler {
private:
    std::string filename;

public:
    FileHandler(const std::string& filename = "data/tasks.dat");
    
    bool saveTasks(TaskManager& manager);
    bool loadTasks(TaskManager& manager);
    bool clearFile();
    
private:
    void ensureDataDirectory();
};

#endif
