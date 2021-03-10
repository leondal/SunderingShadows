//Fulll mud placemnet daemon

#include <std.h>

inherit DAEMON;


#define FIVE ({"/d/shadow/room/cave/"})
#define TEN ({"/d/deku/open/","/d/deku/fortress/","/d/koenig/fields/room/"})
#define FIFTEEN ({"/d/deku/forest/"})
#define SEVENTY ({"/d/laerad/wasteland/"})
#define SIXTYFIVE ({"/d/laerad/plains/"})
#define TWENTY ({"/d/tharis/roads/"})
#define FIFTYFIVE ({"/d/tharis/forest/forest*"})
#define SIXTY ({"/d/laerad/parnelli/forest/"})
#define TWENTYFIVE ({"/d/dagger/road/"})
#define SEVENTYFIVE ({"/d/dagger/road/"})
#define THIRTY ({"/d/dagger/drow/rooms/"})
#define THIRTYFIVE ({"/d/dagger/marsh/swamp/rooms/"})
#define FOURTY ({"/d/attaya/"})
#define FOURTYFIVE ({"/d/attaya/base/"})
#define FIFTY ({"/d/dagger/marsh/tower/rooms/"})
#define PLACES ([70:SEVENTY,75:SEVENTYFIVE,5:FIVE,10:TEN,20:TWENTY,25:TWENTYFIVE,30:THIRTY,35:THIRTYFIVE,40:FOURTY,45:FOURTYFIVE,50:FIFTY,15:FIFTEEN,55:FIFTYFIVE,60:SIXTY,65:SIXTYFIVE])
#include <security.h>
#define SAVEFILE "/daemon/save/place"


string *rooms;

string *items;



void RESTORE(){
   seteuid(UID_DAEMONSAVE);
   restore_object(SAVEFILE);
   seteuid(getuid());
   }

void SAVE(){
   seteuid(UID_DAEMONSAVE);
   save_object(SAVEFILE);
   seteuid(getuid());

}


void setup_places(){
   int i,j,num,num2;
   string *key,*dirs,dir,room,name,exit;
   j = sizeof(rooms);
   if(j){
      for(i=0;i<j;i++){
	 num = random(sizeof(key = keys(PLACES)));
    	 num2 = random(sizeof(PLACES[key[num]]));
	 dir = PLACES[key[num]][num2];
	 dirs = get_dir(dir+"*.c");
	 room = dirs[random(sizeof(dirs))];
	 room = dir+room;
	 sscanf(rooms[i],"%s&%s",name,exit);
	 "/daemon/room_d"->set_mobil_rooms(room,name,exit);
	 "/daemon/room_d"->set_mobil_rooms(name,room,"out");

	
      }
   }
}

void set_rooms(string room,string exit){
   rooms += ({room+"&"+exit});
   distinct_array(rooms);
   SAVE();
}

void create(){
   ::create();

   RESTORE();
   if(!rooms)
      rooms = ({});
   if(!items)
      items = ({});
   SAVE();

   setup_places();
}
