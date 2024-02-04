#include <iostream>
#include <vector>
using namespace std;

int SESSION_START_HOUR_INDEX = 0;
int SESSION_START_MINUTE_INDEX = 3;
int SESSION_END_HOUR_INDEX = 6;
int SESSION_END_MINUTE_INDEX = 9;
int START_OF_DAY_HOUR = 12;
int START_OF_DAY_MINUTE = 0;
int END_OF_DAY_HOUR = 20;
int END_OF_DAY_MINUTE = 0;
string SESSION_INPUT_END = "#";
string DELIMITER = "-";
string COLON = ":";
string SPACE = " ";


typedef struct Time {
    int hour;
    int minute;
} Time;

typedef struct Task {
    int duration;
    int rangeId;
    int taskId;
} Task;

typedef struct TimeRange {
    Time start;
    Time end;
} TimeRange;

Time newTimeMaker(int hour, int minute){
    Time newTime;
    newTime.hour = hour;
    newTime.minute = minute;
    return newTime;
}

TimeRange newTimeRangeMaker(Time start, Time end){
    TimeRange newTimeRange;
    newTimeRange.start = start;
    newTimeRange.end = end;
    return newTimeRange;
}

vector<TimeRange> addNewSession(string input, vector<TimeRange>sessions){
    int startHour = stoi(input.substr(SESSION_START_HOUR_INDEX, 2));
    int startMinute = stoi(input.substr(SESSION_START_MINUTE_INDEX, 2));
    Time start = newTimeMaker(startHour, startMinute);
    int endHour = stoi(input.substr(SESSION_END_HOUR_INDEX, 2));
    int endMinute = stoi(input.substr(SESSION_END_MINUTE_INDEX, 2));
    Time end = newTimeMaker(endHour, endMinute);
    TimeRange newSession = newTimeRangeMaker(start, end);
    sessions.push_back(newSession);
    return sessions;
}

vector<Task> addNewTask(int duration,int rangeId, vector<Task>tasks){
    Task newTask;
    newTask.duration = duration;
    newTask.rangeId = rangeId;
    newTask.taskId = tasks.size() + 1;
    tasks.push_back(newTask);
    return tasks;
}

vector<TimeRange> getSessionInput(vector<TimeRange> sessions){
    string input;
    bool inputFinished = false;
    while (!inputFinished){
        cin >> input;
        if (input!=SESSION_INPUT_END){
            sessions = addNewSession(input, sessions);
            inputFinished = false;
        }
        else{
            inputFinished = true;
        }
    }
    return sessions;
}

vector<Task> getTaskInput(vector<Task> tasks){
    int duration, rangeId;
    bool inputFinished = false;
    while (!inputFinished){
        if (cin >> duration >> rangeId){
            tasks = addNewTask(duration, rangeId, tasks);
            inputFinished = false;
        }
        else{
            inputFinished = true;
        }
    }
    return tasks;
}

bool timeEqual(Time time1, Time time2){
    return (time1.hour == time2.hour && time1.minute == time2.minute);
}

bool isStartOfDayEmpty(TimeRange firstSession){
    Time startOfDay = newTimeMaker(START_OF_DAY_HOUR, START_OF_DAY_MINUTE);
    return !timeEqual(firstSession.start, startOfDay);    
}

bool isEndOfDayEmpty(TimeRange lastSession){
    Time endOfDay = newTimeMaker(END_OF_DAY_HOUR, END_OF_DAY_MINUTE);
    return !timeEqual(lastSession.end, endOfDay);    
}

vector<TimeRange> findEmptyRanges(vector<TimeRange> emptyRanges, vector<TimeRange> sessions){
     if (isStartOfDayEmpty(sessions[0])){
         Time startOfDay = newTimeMaker(START_OF_DAY_HOUR, START_OF_DAY_MINUTE);
         TimeRange newEmptyRange = newTimeRangeMaker(startOfDay, sessions[0].start);
         emptyRanges.push_back(newEmptyRange);
     }
     for (int i = 0 ; i<sessions.size() - 1 ; i++){
         TimeRange currentSession = sessions[i];
         TimeRange nextSession = sessions[i+1];
         if (!timeEqual(currentSession.end, nextSession.start)){
            TimeRange newEmptyRange = newTimeRangeMaker(currentSession.end, currentSession.start);
            emptyRanges.push_back(newEmptyRange);
         }
     }
     int lastIndex = sessions.size() - 1;
     if (isEndOfDayEmpty(sessions[lastIndex])){ 
        Time endOfDay = newTimeMaker(END_OF_DAY_HOUR, END_OF_DAY_MINUTE);
        TimeRange newEmptyRange = newTimeRangeMaker(sessions[lastIndex].end, endOfDay);
        emptyRanges.push_back(newEmptyRange);
     }
     return emptyRanges;
}

Time minuteToHourAndMinute(int minute){
    int hour = minute / 60;
    minute = minute % 60;
    return newTimeMaker(hour, minute);
}

Time addTime(Time time1, Time time2){
    int minute = time1.minute + time2.minute;
    int hour = time1.hour + time2.hour + minute / 60;
    minute = minute % 60;
    return newTimeMaker(hour, minute);
}

TimeRange findTimeRangeForTask(Task task, vector<TimeRange> emptyRanges){
    Time startOfEmptyRange = emptyRanges[task.rangeId - 1].start;
    Time start = startOfEmptyRange;
    Time taskDuration = minuteToHourAndMinute(task.duration);
    Time end = addTime(startOfEmptyRange, taskDuration);
    return newTimeRangeMaker(start, end);
}

vector<TimeRange> updateStartOfEmptyRange(int rangeId, Time rangeNewStart, vector<TimeRange> emptyRanges){
    emptyRanges[rangeId - 1].start = rangeNewStart;
    return emptyRanges;
}

void printTime(Time time){
    cout << time.hour << COLON;
    if (time.minute < 9){
        cout << "0" << time.minute;
    }
    else{
        cout << time.minute;
    }
}

void printTaskTimeRange(int taskId, TimeRange taskTimeRange, bool isLastTask){
    Time start = taskTimeRange.start;
    Time end = taskTimeRange.end;
    cout << taskId << SPACE;
    printTime(taskTimeRange.start);
    cout << DELIMITER;
    printTime(taskTimeRange.end);
    if (!isLastTask){
        cout << endl;
    }
}

int main(){
    vector<TimeRange> sessions;
    vector<Task> tasks;
    vector<TimeRange> emptyRanges;
    sessions = getSessionInput(sessions);
    tasks = getTaskInput(tasks); 
    emptyRanges = findEmptyRanges(emptyRanges, sessions);
    for (auto task:tasks){
        TimeRange taskTimeRange = findTimeRangeForTask(task, emptyRanges);
        emptyRanges = updateStartOfEmptyRange(task.rangeId, taskTimeRange.end, emptyRanges);
        bool islastTask = task.taskId == tasks.size();
        printTaskTimeRange(task.taskId, taskTimeRange, islastTask);
    }  
      
}