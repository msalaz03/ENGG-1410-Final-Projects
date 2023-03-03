#include <math.h>
#include <stdio.h>
#include <string.h>


//All user information
typedef struct user_t {
  char name[50];
  double time;
  double longitude;
  double latitude;
  double altitude;
} user_t;




//name and distance
typedef struct position {
  char name[50];
  double distance;
} position;


//other users and our user
user_t scan_user() {
  user_t info;
  printf("Name: ");
  scanf("%s", info.name);
  printf("Time: ");
  scanf("%lf", &info.time);
  printf("Longitude: ");
  scanf("%lf", &info.longitude);
  printf("Latitude: ");
  scanf("%lf", &info.latitude);
  printf("Altitude: ");
  scanf("%lf", &info.altitude);
  return info;
}




//finds the distance between both people
void findDistance(user_t org, user_t temp1[], position temp2[], int j) {
  for (int i = 0; i < j; i++) {
    strcpy(temp2[i].name, temp1[i].name);
    temp2[i].distance = sqrt(((org.longitude - temp1[i].longitude) *  (org.longitude - temp1[i].longitude)) +
                             ((org.latitude - temp1[i].latitude) * (org.latitude - temp1[i].latitude)) +
                             ((org.altitude - temp1[i].altitude) * (org.altitude - temp1[i].altitude)));


   
   
  }
}
//scans the file line by line
int scanUserFile(user_t data[], char fileName[]) {
  FILE *f1 = fopen(fileName, "r");
  int count;
  fscanf(f1, "%d", &count); //get array size
  for (int i = 0; i < count; ++i) {
    fscanf(f1, "%s", data[i].name);
    fscanf(f1, "%lf", &data[i].time);
    fscanf(f1, "%lf", &data[i].longitude);
    fscanf(f1, "%lf", &data[i].latitude);
    fscanf(f1, "%lf", &data[i].altitude);
    //scans line to fill up data
  }
  return count;
}
//will find the closest person by comparing distance
position findCUser(position temp2[], int j) {
  position temp;
  temp = temp2[0];
  for (int i = 1; i < j; ++i) {
    if (temp2[i].distance < temp.distance) {
      temp = temp2[i];
    }
  }
  return temp;
}


//declare functions
user_t scan_user();
void scanOtherUser(user_t temp[], int x);
void findDistance(user_t org, user_t temp1[], position temp2[], int x);
position findCUser(position temp2[], int x);
int scanUserFile(user_t data[], char fileName[]);


int main() {
 
char fileName[50];
printf("Please enter file Name: "); //get file name from user
scanf("%s", &fileName);


FILE *f1 = fopen(fileName, "r");


if (f1 == NULL){
  printf("FILE DOES NOT EXIST");
}
else {
    user_t our_user;
    our_user = scan_user(); //fill our user data
    user_t otherUser[255]; //struct + string size
    int userCount = scanUserFile(otherUser, fileName); //uCount is the return value from the array that is found file name
    position otherUserposition[userCount]; //array is big as what is in the userFile.
    findDistance(our_user, otherUser, otherUserposition, userCount);
    position cUser; //declare postion user to compare
    cUser = findCUser(otherUserposition, userCount); //compare other user for the size of the array
    //print statement
    printf("\nThe closest person to %s is\n", our_user.name);
    printf("Name: %s", cUser.name);
    printf("\nDistance: %.3lf\n", cUser.distance);


   
}
fclose(f1);


 
  return 0;
}


