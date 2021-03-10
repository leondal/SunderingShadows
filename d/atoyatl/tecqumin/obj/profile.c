
#include <std.h>
#include <daemons.h>

inherit OBJECT;

void init(){
    ::init();
    add_action("read","read");
}

void create(){
    ::create();

    set_name("profile");
    set_id(({"profile","area profile"}));
    set_short("Area profile");
    set_long(
      "This is a general profile of this continent.  It will tell you important information about it."
    );
    set_weight(100000);
    set_value(10000);
}

int read(string str){
    if(!str || str != "profile") return  0;

    tell_room(environment(TO),TPQCN+" reads the area profile!",TP);
    write("Area Name: Danger.\n");
    write("Area Type: continent.\n");
    write("Climate: temperate.\n");
    write("Location: <50'11>.\n\n");
    write("Difficulty Ranking: Oh my god.\n");
    write("Monster Frequency: varies/high.\n");
    write("Sphere of Influence: Tecqumin.\n");
    write("%^BOLD%^%^CYAN%^Lost City of the Tecqumin - area information\n\n");

write("%^CYAN%^Theme: A lost city in a thick jungle on the Continent of Atoyatl Tepexitl.\nWhat could go wrong?");
write("Advised level: 41+");
    write("*Parties recommended.\n");

write("%^BOLD%^%^RED%^NOTE There is an error in some rooms in this area, which is causing casting to fail if you %^RESET%^<look>%^BOLD%^%^RED%^ in between initiating casting and the spell coming into effect. I think it can be avoided by not doing anything in between starting a spell and it coming into effect, but please keep me posted if any further casting (or other) errors occur\n\n");

write("This area is mostly designed as a questing area for players at or near end-game. While there are certainly fights to be had and exploration to be done, the main emphasis is story-based questing. It has a number of bits of new and custom code, which mean that some things won't work the way you might be used to. (Since much of this code is new & experimental, it also means that it might well go wrong. Apologies in advance!)\n\n");

write("%^ORANGE%^NPCs");

write("Many of the quest based NPCs have a lot of information that they can give in conversation, and talking to the various NPCs is necessary to follow the main quest lines. Some of this information may only be available after you have completed other bits of the quest, so it is often worth returning to NPCs you have talked to before, to see if you can discover anything new from them.\n\n");

write("Some of the NPCs will stay dead for a while if you kill them, which may prevent you from finishing the quests. Killing the NPCs may be necessary to follow certain quest lines, but killing them at whim is not advised. (It is possible for the NPCs to be dead to certain PCs but not to others. If you are in a group with someone who has killed an NPC that you haven't killed, it should be possible to identify who has caused the problem, in case you want to eject that PC from your group and continue with your quest.\n\n");

write("Certain mobs and NPCs are good at finding their way round on their own, which means that not all monster movement is random or purposeless.\n\n");

write("%^BOLD%^%^WHITE%^Maps and mazes");

write("Some areas have maps that change from time to time. So, while mapping may be necessary to find your way round, your map might not be entirely useful the next time you visit. It should be reasonably obvious from room descriptions which areas this applies to.\n");

write("Because the map may change while you are logged out, it is also possible to log in to a room that is no longer included in the map - in which case you will be ejected to a suitable room outside of the changed area.\n\n");

write("%^GREEN%^Problem solving");

write("In all traps and puzzles, I've tried to make all syntax as intuitive as possible, and to include hints and multiple options for using it. I've also tried to include multiple possible ways of doing things, where possible.\n ");

write("If you find somewhere that syntax is tricky, please let me know so I can try to do something about it.\n");

write("If you think of an original or ingenious way that you would like to solve a puzzle or challenge, which is not coded for, please feel free to suggest it - I'll consider trying to add it in as an option.\n\n");

write("%^BOLD%^%^BLUE%^Visual elements");

write("I've played around with ASCII based visual elements in some areas. These work best if you have a terminal that can display ANSI colours, including background colours, and if your screen width is set to at least 75 (using SETENV). Where possible, I've tried to include text-only options for those who can't use the visual features. If anyone is unable to solve a bit of the quest as a result of problems with using the visual features (e.g. if they are on a phone client, or using a text reader), it is permissible to seek assistance from another player who can use them. I can only apologise to anyone who can't enjoy all of the area's challenges because of this.\n\n");

write("%^ORANGE%^Context sensitive help");

write("Some items have specific uses that only apply in certain places or contexts. Where appropriate, they may have extra hints in their descriptions when they are in the right place or context to be used.\n\n");

write("%^BOLD%^%^RED%^Fighting");

write("Building and balancing mobs isn't my forte. Chances are mobs will need to be balanced for difficulty based on player feedback. Some battles allow for non-traditional methods to be used to shift things in your favour. Some may be more or less unwinnable without doing so.\n");

write("Depending on the route you take, it may also be possible to complete at least some of the quests with little or no fighting.\n\n");

write("%^BOLD%^%^WHITE%^Rewards\n\n");

write("I've tried to include a reasonable range of suitable and original reward items, and will probably add new items as options as time goes on. If there's something you'd love to see in the quest rewards, I'll be open to considering special requests.\n\n");

write("%^BOLD%^%^RED%^NOTE There is an error in some rooms in this area, which is causing casting to fail if you %^RESET%^<look>%^BOLD%^%^RED%^ in between initiating casting and the spell coming into effect. I think it can be avoided by not doing anything in between starting a spell and it coming into effect, but please keep me posted if any further casting (or other) errors occur\n\n");

write("%^B_GREEN%^%^BOLD%^%^GREEN%^Have fun!");

write("%^B_GREEN%^%^BOLD%^%^GREEN%^Lujke");
    return 1;
}
