#include <std.h>

inherit MONSTER;

void create() {
    ::create();
    set_name("ogre escapee");
    set_id( ({"ogre", "escapee", "ogre escapee", "cavemon"}) );
    set_short("Ogre escapee");
    set_long(
      "This is a beaten and weakened ogre female.  She looks to have gone through hell to get where she is now, but now she sits on the muddy red floor, breathing weakly."
    );
    set_gender("female");
    set("race","ogre");
    set_body_type("human");
    set_overall_ac(5);
    set_hd(5,1);
    set("aggressive",3);
    set_size(3);
    set_max_hp(30);
    set_hp(30);
    set_emotes(5, ({
	"The ogress sits on the floor and mutters to herself.  Perhaps you could get her attention by nodding to her.",
      }),0);
}

void init() {
    ::init();
    add_action("nod_fcn","nod");
}



int nod_fcn(string str) {
    if(!str) { return 0; }

    if( (str == "ogre") || (str == "escapee") || (str == "ogre escapee") || (str == "ogress") ) {
	message("environment",
	  "The ogress coughs weakly as you nod to her.\n"
	  +"The ogress raises her eyes to the roof of the cave and says:  Thank you gods!  You have answered my prayers and sent the heros to help my people!"
	  +"The ogress looks at you and speaks\n\n"
	  +"  I pray you are the brave adventurers sent to save my people.  I am of the ogres of the midnight caves, and I am the only one to escape a horrid scourge upon us.   Many moons ago we were a happy and peaceful people, but then a strange ogre came to us.  "
	  +"He claimed to have come from the deeper pits of the caves, and claimed that he had found great power there, and indeed he had.  He had gained the power of magic.\n   He offered to show some of the men of our village the secret, and overjoyed to be able to protect ourselves from the evil of the world, they agreed and went with him.  They returned changed.  Soon more and more men went with them, and even some of the women.  "
	  +"Soon I joined them too, as I was one of the smartest of our tribe.  What I found was our doom.\n\n"
	  +"   It turned out that the ogre-magi had been gaining their power from demonic posession.  I don't remember how, but I escaped, and I ended up here.  Please, I beg of you, rescue my people from the evil that has posessed them, and seal the gate to hell that the demons are coming through before it is too late for all of us."
	  +"\n\n   I will warn you though, it is dangerous.   There are few exits from the caves, and the first thing the demons did was protect the caves against the magic of teleportation.  It will be difficult to get out once you enter."
	  +"\n   There is one that may be able to help you.  The healer of our village, wise in the way of potions, healing, and even curses, escaped and is still in the caves to help anyone who comes and tries to help our people.  Her workshop is hidden by illusion, but is not hard to find if you look."
	  +"\n\n   With that the ogre breathes her last breath and collapses dead on the ground."
	  ,environment(TO));
	TO->die();
	return 1;
    }
}


int should_interact(object ob) { return 1;}
