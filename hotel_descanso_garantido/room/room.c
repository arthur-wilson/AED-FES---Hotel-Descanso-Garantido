// #include "room.h"
#include <stdio.h>

typedef struct
{
    int id;
    int maxNumberOfGuests;
    double valuePerDay;
    int status;

} Room;

typedef struct
{
    int containsRoom;
    Room room;

} ReturnRoom;

FILE *openRoomDatabase()
{
    char roomDatabaseName[] = "./database/room_database.dat";
    FILE *roomDatabase;
    roomDatabase = fopen(roomDatabaseName, "a+b");
    return roomDatabase;
}

int saveRoom(Room room)
{
    FILE *roomDatabase = openRoomDatabase();
    unsigned long roomByteSize = sizeof(room);

    fseek(roomDatabase, 0, SEEK_END);
    fwrite(&room, roomByteSize, 1, roomDatabase);
    fflush(roomDatabase);
}

ReturnRoom getRoomById(int searchId)
{
    FILE *roomDatabase = openRoomDatabase();
    Room foundedRoom;
    ReturnRoom returnRoom = {.containsRoom = 0};

    unsigned long sizeOfRoomInBytes = sizeof(foundedRoom);

    fseek(roomDatabase, 0, SEEK_SET);
    fread(&foundedRoom, sizeOfRoomInBytes, 1, roomDatabase);
    int isEndOfDatabase = feof(roomDatabase);

    while (!isEndOfDatabase)
    {
        if (foundedRoom.id == searchId)
        {
            returnRoom.containsRoom = 1;
            returnRoom.room = foundedRoom;
            break;
        }
        else
        {
            fread(&foundedRoom, sizeOfRoomInBytes, 1, roomDatabase);
            isEndOfDatabase = feof(roomDatabase);
        }
    }

    return returnRoom;
}

int isRoomAlreadyInDatabase(int searchId)
{
    ReturnRoom returnRoom = getRoomById(searchId);

    return returnRoom.containsRoom;
}

void registerRoom()
{
    int roomId, maxNumberOfGuests;
    double valuePerDay;
    int roomDefaultStatus = 0;

    printf("Insira o número do quarto que deseja cadastrar: ");
    scanf("%i", &roomId);

    if (!isRoomAlreadyInDatabase(roomId))
    {

        printf("Insira o número máximo de pessoas que o quarto suporta: ");
        scanf("%i", &maxNumberOfGuests);
        printf("Insira o valor da diária: ");
        scanf("%lf", &valuePerDay);

        Room newRoom = {
            .id = roomId,
            .maxNumberOfGuests = maxNumberOfGuests,
            .valuePerDay = valuePerDay,
            .status = roomDefaultStatus};

        saveRoom(newRoom);
    }
    else
    {
        printf("Um Quarto com esse número já existe!");
    }
}