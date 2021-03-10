#include <std.h>
inherit ROOM;

void create()
{
    ::create();
    set_property("indoors", 1);
    set_property("light", 1);
    set("short", "Randomizer");
    set("long",
	"You are waiting to be mixed up with everything else in "+
	"the room, then sent back.\n");
}

void randomize(object prev_room, object *request)
{
    int num, num2, randnum;
    object *temp;
    while(sizeof(request) != ({}))
    {
	temp=allocate(sizeof(request)-1);
	randnum=random(sizeof(request));
	request[randnum]->move(prev_room);
	for(num=0;num<=sizeof(request)-1;num++)
	{
	    if(num != randnum)
	    {
		temp[num2]=request[num];
		num2++;
	    }
	}
	request=temp;
    }
}
