#ifdef ROOM_H_
#define ROOM_H_

typedef struct ReturnRoom;
void registerRoom();
ReturnRoom getRoomById(int searchId);
ReturnRoom getRoomByNumberOfGuests(int searchNumberOfGuests);
int isRoomAlreadyInDatabase(int searchId);
void registerRoom();

#endif