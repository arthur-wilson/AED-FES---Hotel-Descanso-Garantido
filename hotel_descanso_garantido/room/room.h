#ifdef ROOM_H_
#define ROOM_H_

typedef struct ReturnRoom;
void registerRoom();
ReturnRoom getRoomById(int searchId);
int isRoomAlreadyInDatabase(int searchId);
void registerRoom();

#endif