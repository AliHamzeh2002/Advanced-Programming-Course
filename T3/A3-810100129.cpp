#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;

const int FILE_NAME_INDEX = 1;
const int NAME_INPUT_INDEX = 0;
const int TIME_START_INPUT_INDEX = 1;
const int TIME_END_INPUT_INDEX = 2;
const char SPACE = ' ';
const char ENTER = '\n';
const char DELIMITER = ':';
const char UNDERLINE = '-';

struct Time{
    int hour;
    int minute;
};

struct TimeRange{
    Time start;
    Time end;
};

struct Translator{
    string name;
    vector<TimeRange> freeTimeRanges;
    vector<string> knownLanguages;
};

const Translator NO_TRANSLATORS = {"Not Found"};

struct Event{
    string name;
    TimeRange eventTimeRange;
    vector<string> neededLanguages;
    vector<string> translators;
};

typedef vector<Translator> TranslatorsList;
typedef vector<Event> EventsList;

vector<string> splitBySpace(string str){
    vector<string> splitted;
    int initialIndex = 0;
    for (int i = 0 ; i < str.size() ; i++){
        char currentChar = str[i];
        if (currentChar == SPACE){
            string newStr = str.substr(initialIndex, i - initialIndex);
            splitted.push_back(newStr);
            initialIndex = i + 1;
        }
    }
    string newStr = str.substr(initialIndex, str.size() - initialIndex);
    splitted.push_back(newStr);
    return splitted; 
}

Time createNewTime(int hour, int minute){
    Time newTime;
    newTime.hour = hour;
    newTime.minute = minute;
    return newTime;
}

Time readStringTime(string strTime){ 
    int hour = stoi(strTime.substr(0, 2));
    int minute = stoi(strTime.substr(3, 2));
    return createNewTime(hour, minute);
}

TimeRange createNewTimeRange(Time start, Time end){
    TimeRange newTimeRange;
    newTimeRange.start = start;
    newTimeRange.end = end;
    return newTimeRange;
}

Translator createNewTranslator(string name, Time start, Time end, vector<string> languages){
    Translator newTranslator;
    newTranslator.name = name;
    newTranslator.freeTimeRanges.push_back(createNewTimeRange(start, end));
    newTranslator.knownLanguages = languages;
    return newTranslator;
}

Translator readTranslatorData (string data){
    vector<string> splitted = splitBySpace(data);
    string name = splitted[NAME_INPUT_INDEX];
    Time start = readStringTime(splitted[TIME_START_INPUT_INDEX]);
    Time end = readStringTime(splitted[TIME_END_INPUT_INDEX]);
    vector<string> languages;
    for (int i = 3 ; i < splitted.size(); i++){
        languages.push_back(splitted[i]);
    }
    return createNewTranslator(name, start, end, languages);
}

TranslatorsList readTranslatorsFromFile(ifstream& inputFile){
    string firstLine;
    getline(inputFile, firstLine);
    int numberOfTranslators = stoi(firstLine);
    TranslatorsList translators;
    string line;
    for (int i = 0; i < numberOfTranslators; i++){
        getline(inputFile, line);
        Translator translator = readTranslatorData(line);
        translators.push_back(translator);
    }
    return translators;
}

Event createNewEvent(string name, Time start, Time end, vector<string> languages){
    Event newEvent;
    newEvent.name = name;
    newEvent.eventTimeRange = createNewTimeRange(start, end);
    newEvent.neededLanguages = languages;
    newEvent.translators.resize(languages.size());
    return newEvent;
}

Event readEventData(string data){
    vector<string> splitted = splitBySpace(data);
    string name = splitted[NAME_INPUT_INDEX];
    Time start = readStringTime(splitted[TIME_START_INPUT_INDEX]);
    Time end = readStringTime(splitted[TIME_END_INPUT_INDEX]);
    vector<string> languages;
    for (int i = 3 ; i < splitted.size(); i++){
        languages.push_back(splitted[i]);
    }
    return createNewEvent(name, start, end, languages); 
}

EventsList readEventsListFromFile(ifstream& inputFile){
    string firstLine;
    getline(inputFile, firstLine);
    int numberOfEvents = stoi(firstLine);
    EventsList events;
    string line;
    for (int i = 0; i < numberOfEvents; i++){
        getline(inputFile, line);
        Event event = readEventData(line);
        events.push_back(event);
    }
    return events;
}

bool knowLanguage(string language, Translator translator){
    vector<string> knownLanguages = translator.knownLanguages;
    return (count(knownLanguages.begin(), knownLanguages.end(), language));
}
int numTranslatorsForLanguage(string language, TranslatorsList translators){
    int result = 0;
    for (auto translator : translators){
        if (knowLanguage(language, translator))
            result++;
    }
    return result;
}

vector<string> sortLanguages(vector<string> languages, TranslatorsList translators){
    for (int i = 0; i < languages.size() - 1; i++){
        for (int j = 0; j < languages.size() - i - 1; j++){
            if (numTranslatorsForLanguage(languages[j], translators) > numTranslatorsForLanguage(languages[j+1], translators)){
                swap(languages[j], languages[j+1]);
            }
        }
    }
    return languages;
}

int findElementIndex(string str, vector<string> vec){
    return find(vec.begin(), vec.end(), str) - vec.begin();
}

bool isAfter(Time t1, Time t2){
    return ((t1.hour > t2.hour) || (t1.hour == t2.hour && t1.minute >= t2.minute));
}

bool isBefore(Time t1, Time t2){
    return isAfter(t2, t1);
}

bool isInFreeTimeRange(TimeRange timeRange, TimeRange freeTimeRange){
    return (isAfter(timeRange.start, freeTimeRange.start) && isBefore(timeRange.end, freeTimeRange.end));
}

bool isFreeInTimeRange(TimeRange timeRange, vector<TimeRange> freeTimeRanges){
    for (auto freeTimeRange : freeTimeRanges){
        if (isInFreeTimeRange(timeRange, freeTimeRange)){
            return true;
        }
    }
    return false;
}

TranslatorsList findPossibleTranslators(TimeRange eventTimeRange, string language, TranslatorsList translators){
    TranslatorsList possibleTranslators;
    for (auto translator : translators){
        if (knowLanguage(language, translator) && isFreeInTimeRange(eventTimeRange, translator.freeTimeRanges)){
            possibleTranslators.push_back(translator);
        }
    }
    return possibleTranslators;
}

bool isBetterTranslatorOption(Translator newOption, Translator prevOption){
    return ((newOption.knownLanguages.size() < prevOption.knownLanguages.size()) ||
           ((newOption.knownLanguages.size() == prevOption.knownLanguages.size()) && 
            newOption.name.compare(prevOption.name) < 0) );
}

Translator chooseBestTranslator(TranslatorsList possibleTranslators){
    Translator bestTranslator = possibleTranslators[0];
    for (auto translator : possibleTranslators){
        if (isBetterTranslatorOption(translator, bestTranslator)){
            bestTranslator = translator;
        }
    }
    return bestTranslator;
}
Translator findTranslatorForLanguage(TimeRange eventTimeRange, string language, TranslatorsList translators){
    TranslatorsList possibleTranslators = findPossibleTranslators(eventTimeRange, language, translators);
    if (possibleTranslators.size() == 0){
        return NO_TRANSLATORS;
    }
    Translator bestPossibleTranslator = chooseBestTranslator(possibleTranslators);
    return bestPossibleTranslator;
}

vector<string> getNamesList(TranslatorsList translators){
    vector<string> names;
    for (auto translator : translators){
        names.push_back(translator.name);
    }
    return names;
}

void printTimeRange(TimeRange tr){
    cout << tr.start.hour << DELIMITER << tr.start.minute << UNDERLINE << tr.end.hour << DELIMITER << tr.end.minute << endl;
}

void updateTranslatorFreeTimeRange(int translatorIndex, TimeRange eventTimeRange, TranslatorsList& translators){
    Translator translator = translators[translatorIndex];
    vector<TimeRange> newFreeTimeRanges;
    for (int i = 0; i < translator.freeTimeRanges.size(); i++){
        if (isInFreeTimeRange(eventTimeRange, translator.freeTimeRanges[i])){
            TimeRange tr1 = createNewTimeRange(translator.freeTimeRanges[i].start, eventTimeRange.start);
            TimeRange tr2 = createNewTimeRange(eventTimeRange.end, translator.freeTimeRanges[i].end);
            newFreeTimeRanges.push_back(tr1);
            newFreeTimeRanges.push_back(tr2);
        }
        else{
            newFreeTimeRanges.push_back(translator.freeTimeRanges[i]);
        }
    }
    translator.freeTimeRanges = newFreeTimeRanges;
    translators[translatorIndex] = translator;
}

Event manageTranslatorsForEvent(Event event, TranslatorsList& translators){
    vector<string> languagePriority = sortLanguages(event.neededLanguages, translators);
    for (string language : languagePriority){
        Translator translator = findTranslatorForLanguage(event.eventTimeRange, language, translators);
        if (translator.name != NO_TRANSLATORS.name){
            int translatorIndex = findElementIndex(translator.name, getNamesList(translators));
            updateTranslatorFreeTimeRange(translatorIndex, event.eventTimeRange, translators);
        }
        int languageIndex = findElementIndex(language, event.neededLanguages);
        event.translators[languageIndex] = translator.name;
    }
    return event;
}

EventsList manageTranslatorsForEventsList(EventsList events, TranslatorsList& translators){
    for (int i = 0; i < events.size(); i++){
       events[i] = manageTranslatorsForEvent(events[i], translators);
    }
    return events;
}

void printEvent(Event event){
    cout << event.name << endl;
    for (int i = 0 ; i < event.neededLanguages.size(); i++){
        string language = event.neededLanguages[i];
        string translator = event.translators[i];
        cout << language << DELIMITER << SPACE << translator << endl ;
    }
}

void printEvents(EventsList events){
    for (int i = 0; i < events.size(); i++){
        Event event = events[i];
        printEvent(event);
    }
}

int main(int argc, char* argv[]){
    string dataFileName = argv[FILE_NAME_INDEX];
    ifstream inputFile(dataFileName);
    TranslatorsList transaltors = readTranslatorsFromFile(inputFile);
    EventsList events = readEventsListFromFile(inputFile);
    inputFile.close();
    events = manageTranslatorsForEventsList(events, transaltors);
    printEvents(events);
    return 0;
}