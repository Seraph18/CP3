#Aligns word lists next to each other, one from each on each line

#Activity creator: /usr/bin/python3 */generalCombiner.py storageFiles/ActivityFile.txt StringCombinerScript/textLists/ListOfActivities.txt StringCombinerScript/textLists/ListOfUserNames.txt StringCombinerScript/VenueCombiner/ListOfVenues.txt StringCombinerScript/textLists/ListOfExclusive.txt

import random
import sys



def generateRandomDates(): #MM-DD-YYYY
    startMonth = random.randint(1, 12)
    startDay = random.randint(1, 30)
    startYear = random.randint(1776, 2021)

    endYear = random.randint(startYear, 2021)
    if(startYear == endYear):
        endMonth = random.randint(startMonth, 12)
    else:
        endMonth = random.randint(1, 12)
    if(startMonth == endMonth):
        endDay = random.randint(startDay, 30)
    else:
        endDay = random.randint(1, 30)

    if(startMonth < 10):
        startMonth = "0" + str(startMonth)
    if(startDay < 10):
        startDay = "0" + str(startDay)
    if(endMonth < 10):
        endMonth = "0" + str(endMonth)
    if(endDay < 10):
        endDay = "0" + str(endDay)
    
    

    startDate = str(startMonth) + "-" + str(startDay) + "-" + str(startYear)
    endDate = str(endMonth) + "-" + str(endDay) + "-" + str(endYear)
    
    #HH:MM:SS  
    startMinute = random.randint(1, 59)
    startHour = random.randint(1, 23)
    startSecond = random.randint(1, 59)

    if(startYear == endYear and startMonth == endMonth and startDay == endDay):
        endHour = random.randint(startHour, 23)
        if(startHour == endHour):
            endMinute = random.randint(startMinute, 59)
        else:
            endMinute = random.randint(1, 59)
        if(startMinute == endMinute):
            endSecond = random.randint(startSecond, 59)
        else:
            endSecond = random.randint(1, 59)

    else:
        endMinute = random.randint(1, 59)
        endSecond = random.randint(1, 59)
        endHour = random.randint(1, 23)
    
    if(startHour < 10):
        startHour = "0" + str(startHour)
    if(startMinute < 10):
        startMinute = "0" + str(startMinute) 
    if(startSecond < 10):
        startSecond = "0" + str(startSecond) 

    if(endHour < 10):
        endHour = "0" + str(endHour)
    if(endMinute < 10):
        endMinute = "0" + str(endMinute) 
    if(endSecond < 10):
        endSecond = "0" + str(endSecond) 
    
    startTime = str(startHour) + ":" + str(startMinute) + ":" + str(startSecond)
    endTime = str(endHour) + ":" + str(endMinute) + ":" + str(endSecond)

    timeTuple = (startTime, startDate, endTime, endDate)
    return timeTuple

numberOfFilePaths = len(sys.argv)

if(numberOfFilePaths <= 2):
    print("Usage: /usr/bin/python3 */generalCombiner.py <fileToPrintTo> <readFile1> <readFile2>...")
else:

    wordLists = []
#Add all lists to the wordlists array
    for i in range(2, numberOfFilePaths):
        newFile = open(sys.argv[i], 'r')
        currList = newFile.readlines()
        
        for j in currList:
            currString = j
            currString = currString.strip()
            currString = currString.replace("\n", "")
            currString = currString.replace(" ", "_")
            currList[currList.index(j)] = currString

        wordLists.append(currList)
        newFile.close()
    
    print(sys.argv)
    #Actually add them to the new File
    fileToPrintTo = open(sys.argv[1], 'w')

    lowestIndexCount = sys.maxsize

    for i in wordLists:
        if(lowestIndexCount > len(i)):
            lowestIndexCount = len(i)

    for i in range(lowestIndexCount):
        for j in range(len(wordLists)):
            fileToPrintTo.write(wordLists[j][i])
            if(j != len(wordLists)-1):
                fileToPrintTo.write(" ")

                if(j == 1 and True):
                    dateAndTimes = generateRandomDates()
                    fileToPrintTo.write(dateAndTimes[0] + " " + dateAndTimes[1] + " " + dateAndTimes[2] + " " + dateAndTimes[3] + " ")
            else: 
                fileToPrintTo.write("\n")


    fileToPrintTo.close()


