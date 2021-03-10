#include <std.h>
#include <daemons.h>

#define VAL_DIV 1 /* full market value */
#define MAX_PRICE 100000 /* corresponding...also see /std/vendor.c */
#define VALID_ACTIONS ({ "look", "say", "quit", "help", "mail", "lawmail", "emote", "bboard", "chfn", "emoteat", "describe", "who", "background", "thought", "ignore", "discuss","score","inventory","lore","avatarmail","pkmail", "deceased", "reply", "deceasedemote", "uptime", "finger", "quests", "last", "date", "hm", "hmemote", "tell", "adjective", "message", "speech", "alias", "nickname", "command"})

inherit ROOM;

object DeadPerson;

void release_em(object dead);
void attempt_raise();
int raise_player(string verb);
string what_alignment(int align);

void attempt_raise()
{
    string diety,alignment,type;
    if(!objectp(DeadPerson)) return;
    if(!DeadPerson->query("RaisingRoom")) { return; }

    alignment = what_alignment((int)DeadPerson->query("RaisingPriestAlignment"));
    diety     = (string)DeadPerson->query("RaisingPriestGod");
    type      = (string)DeadPerson->query("RaisingType");

    if(type == "deny the reaper")
    {
        tell_object(DeadPerson,"%^RESET%^%^B_CYAN%^You can feel a pull on your soul.  You sense "
        "the tendrils of a necromancer's arcane energy trying to steal you away from "
        "the afterlife!\nType <accept> to return to life, or <cancel> to leave your "
        "fate in Lysara's hands.%^RESET%^");
        return;
    }

    tell_object(DeadPerson,"%^RESET%^You can feel a pull on your soul.  You sense that someone is trying to return you to life!\nType <accept> to return to life, or <cancel> to leave your fate to a chance.%^RESET%^");
    return;
}

int raise_player(string verb)
{
	object MyDeadRoom;
	string diety,alignment,room,type;
    int loss;

    if(!objectp(DeadPerson)) { return 0; }
    if(avatarp(DeadPerson)) { return 1; }
    if(!DeadPerson->query("RaisingRoom")) { return 0; }

    room      = (string)DeadPerson->query("RaisingRoom");
    loss      = (int)DeadPerson->query("RaisingExpLoss");
    type      = (string)DeadPerson->query("RaisingType");
    //alternative worlds code support - Saide
    if(DeadPerson->query("previous alternative world"))
    {
        DeadPerson->set("alternative world", DeadPerson->query("previous alternative world"));
        DeadPerson->delete("previous alternative world");
    }
    if(!objectp(find_object_or_load(room)))
    {
        DeadPerson->delete("alternative world");
        room = "/d/shadowgate/death/death_exit";
    }

    switch(verb)
    {
        case "accept":
            DeadPerson->revive(loss);
            if(type == "raise dead" || type == "deny the reaper") { DeadPerson->set_hp(10); }
            else { DeadPerson->set_hp((int)DeadPerson->query_max_hp()); }
            DeadPerson->set_heart_beat(1);
            DeadPerson->cease_all_attacks();
            DeadPerson->restrict_channel("deceased");
            MyDeadRoom = DeadPerson->query_property("death_room");
            DeadPerson->remove_property("death_room");
            DeadPerson->move(room);
            DeadPerson->force_me("look");

            DeadPerson->delete("in_the_afterlife");
            DeadPerson->delete("just_been_pkilled");
            DeadPerson->delete("no pk");
            DeadPerson->remove_pk_death_flag();
            DeadPerson->remove_property("death_room");

            DeadPerson->set_death_age(0);
            DeadPerson->delete("RaisingRoom");
            DeadPerson->delete("RaisingPriestAlignment");
            DeadPerson->delete("RaisingPriestGod");
            DeadPerson->delete("RaisingExpLoss");
            DeadPerson->delete("RaisingType");
            tell_object(DeadPerson,"%^BOLD%^You have choosen to return to life!%^RESET%^");
            tell_room(environment(DeadPerson),"%^BOLD%^"+TP->QCN+" has returned from the "+
            "dead!",DeadPerson);
            PERMA_DEATH_D->remove_player(DeadPerson->query_name());

            if (objectp(MyDeadRoom)) {
                MyDeadRoom->remove();
            }
            // intentionally left a break out of here
        case "cancel":
            if(verb == "cancel")
            {
                tell_object(DeadPerson,"%^BOLD%^You have choosen to leave your "+
                "fate in Lysara's hands!%^RESET%^");
            }
            DeadPerson->delete("RaisingRoom");
            DeadPerson->delete("RaisingPriestAlignment");
            DeadPerson->delete("RaisingPriestGod");
            DeadPerson->delete("RaisingExpLoss");
            DeadPerson->delete("RaisingType");
    }
    return 0;
}

string what_alignment(int align)
{
    string alignment;
    switch(align)
    {
    case 1: alignment = "Lawful Good"; break;
    case 2: alignment = "Lawful Neutral"; break;
    case 3: alignment = "Lawful Evil"; break;
    case 4: alignment = "Neutral Good"; break;
    case 5: alignment = "True Neutral"; break;
    case 6: alignment = "Neutral Evil"; break;
    case 7: alignment = "Chaotic Good"; break;
    case 8: alignment = "Chaotic Neutral"; break;
    case 9: alignment = "Chaotic Evil"; break;
    default: alignment = "necromancer"; break;
    }
    return alignment;
}



void create()
{
  	::create();
  	set_light(2);
  	set_indoors(1);
  	set_short("In a haze, awaiting Lysara's Decision");
  	set_property("no starve", 1);
  	set_long("%^BOLD%^%^WHITE%^This is an area void of decoration or "+
		"living objects.  There are no trees, no grass, no water, nor earth.  "+
		"Instead, it is a haze of nothingness where you have been sent while "+
		"Lysara decides your fate.  Around you float the lost souls of others "+
	      "awaiting thier time in front of the Lord of the Dead, and the sheer numbers "+
      	"of them give you a sinking feeling.  While here, you are able to think upon "+
		"your life and decide what you have done that might be worthy of "+
		"his good graces, for you know he holds your future in his hands.  "+
		"All you can do is sit here and hope that someone or something comes "+
		"to plead your case so that you may be once again returned to the land "+
		"of the living and to the things you care most for  You could "+
		"<%^BOLD%^%^CYAN%^ask%^BOLD%^%^WHITE%^> how much longer you "+
		"must wait, but it is doubtful to have much impact.%^RESET%^");
	set_heart_beat(10);
}

void init()
{
	::init();
	if(!objectp(TP)) return;
	//TP->set_ghost(0);
	if(TP->query_paralyzed()) TP->remove_paralyzed();
	if(TP->query_tripped()) TP->remove_tripped();

	if(!objectp(DeadPerson) &&
	(PERMA_DEATH_D->is_perma_deathed(TP->query_name()) ||
	TP->query("in_the_afterlife")))
	{
		DeadPerson = TP;
		if(!(int)DeadPerson->query("in_the_afterlife"))
		{
			DeadPerson->set("in_the_afterlife", 1);
		}
		TP->unrestrict_channel("deceased");
		tell_object(TP, "You can now use the line %^BOLD%^%^WHITE%^deceased%^RESET%^ to talk with other dead.");
	}
	add_action("filter_act","",1);
}

int filter_act(string str)
{
	string tmp, response_str;
	int x;
	if(!objectp(TP)) return 1;
	if(query_verb() == "accept" || query_verb() == "cancel")
	{
		raise_player(query_verb());
		return 1;
	}
	if(query_verb() == "ask")
	{
		tell_object(TP, "%^BOLD%^%^RED%^In a desperate plea you "+
		"yell out into the haze around you - 'HOW MUCH LONGER MUST "+
		"I WAIT HERE!'%^RESET%^");
		if(!objectp(DeadPerson)) return 1;
		if(objectp(DeadPerson))
		{
//			x = (int)DeadPerson->get_perma_death_flag(); //this was not working!
			x = (int)PERMA_DEATH_D->get_permadeath(DeadPerson->query_name()) - time();
			if(x / 10 >= 650)
			{
				response_str = "%^BOLD%^%^RED%^A horde of souls%^RESET%^";
			}
			else if(x / 10 >= 450)
			{
				response_str = "%^BOLD%^%^BLACK%^A vast number of souls%^RESET%^";
			}
			else if(x / 10 >= 300)
			{
				response_str = "%^BOLD%^%^GREEN%^A lot of souls%^RESET%^";
			}
			else if(x / 10 >= 150)
			{
				response_str = "%^BOLD%^%^YELLOW%^many souls%^RESET%^";
			}
			else if(x / 10 < 150 && x / 10 > 50)
			{
				response_str = "%^BOLD%^%^BLUE%^several dozen souls%^RESET%^";
			}
			else if(x / 10 <= 50 && x / 10 >= 13)
			{
				response_str = "%^BOLD%^%^MAGENTA%^several souls%^RESET%^";
			}
			else if(x / 10 == 12)
			{
				response_str = "%^BOLD%^%^GREEN%^a dozen souls%^RESET%^";
			}
			else if(x / 10 < 12)
			{
				response_str = "%^BOLD%^%^CYAN%^only a few souls%^RESET%^";
			}
		}
		tell_object(TP, "%^BOLD%^%^WHITE%^A stern yet patient voice answers you "+
		"from the haze :  %^BOLD%^%^WHITE%^Be patient %^BOLD%^%^CYAN%^"+
		capitalize(DeadPerson->query_name())+
		" %^BOLD%^%^WHITE%^Lysara must see "+response_str+
		" %^BOLD%^%^WHITE%^before he will decide your fate.%^RESET%^");
		return 1;
	}
  	if (member_array(query_verb(), VALID_ACTIONS ) == -1)
	{
		if(avatarp(TP))
		{
			tell_object(TP, "If you were a player you would see "+
			"the following : \n");
		}
		tmp = "%^BOLD%^%^WHITE%^While you patiently await "+
		"Lysara's Decision, you are only able to perform "+
		"the following actions : \n\n";

		tmp += "%^BOLD%^%^CYAN%^" + implode(VALID_ACTIONS, "\n");
		tmp += "\n\n%^BOLD%^%^RED%^You should use this time wisely "+
		"to reflect upon yourself.%^RESET%^\n";
		tell_object(TP, tmp);
		if(!avatarp(TP))
		{
    			return 1;
		}
 	}
}

void release_em(object dead)
{
    object MyDeadRoom;
    if (!objectp(dead)) {
        return;
    }
    if (!userp(dead)) {
        return;
    }
    MyDeadRoom = dead->query_property("death_room");
    //dead->set_ghost(1);
    tell_object(dead, "%^BOLD%^%^WHITE%^You are suddenly " +
                "pulled from this place to face Lysara's Decision!" +
                "%^RESET%^");
    if (dead->query("in_the_afterlife")) {
        dead->delete("in_the_afterlife");
    }
    dead->restrict_channel("deceased");
    dead->set_property("trial", 1);
    dead->move("/d/shadowgate/death/death_room.c");
    dead->remove_property("death_room");
    if (objectp(MyDeadRoom)) {
        MyDeadRoom->remove();
    }
    if (objectp(TO) && clonep(TO)) {
        TO->remove();
    }
    return;
}

void heart_beat()
{
    if (!objectp(DeadPerson)) {
        return;
    }
    if (!PERMA_DEATH_D->is_perma_deathed(DeadPerson->query_name())) {
        release_em(DeadPerson);
        return;
    }
    attempt_raise();
    //::heart_beat();
}
