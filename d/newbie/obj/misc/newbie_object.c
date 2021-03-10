/*===========================================================
Tutorial Object for Newbies - going to have it be a sentient helmet
that changes to either a wizard type hat/coif/or great helm when the tutorial
is completed - based on class

Basically though it is going to direct newbies to areas of the newbie area
to complete quests/tasks and will reward them with gear
as they complete them.

The idea being that newbies will have a set of decent gear when
they leave the newbie area - the helmet itself
will be the only enchanted item - at +1 and will
stay with them leveling up to +3 at level 20 (it will be slightly lower enchantment than what
they might be able to find out in the world).

Will reward experience based on what is needed to level up when the task/quest
is completed - so that by the time a player completes the tasks
they should be non-newbie - the very last task will
reward the updated helmet and spawn a version of a trainer
that is special for a newbie character.

Saide, November 2016

================================================================*/
#include <std.h>
#include <daemons.h>
#define NEWB_D "/d/newbie/ooc/newbie_d.c"

inherit OBJECT;
string belongsTo, *explained;
int myTask, myPlace, myAlign, myTimer;
void advance_task();
varargs string determine_explaination(string which);

string myLong()
{
    string tmp, *tmp2;
    tmp = "%^BOLD%^%^YELLOW%^This strange brilliant mass is composed of an unknown material. "+
    "It has no markings of any kind that you are able to discern. It seems quite sturdy but also "+
    "amazingly flexible. Simply looking at it, however, seems to fill you with hope or perhaps "+
    "excitement. The urge to %^RED%^ask%^BOLD%^%^YELLOW%^ it something also fills your mind. \n\nThe "+
    "mass is also able to %^RED%^explain%^BOLD%^%^YELLOW%^ things to you. Currently it will explain "+
    "the following:\n\n%^YELLOW%^";
    tmp2 = explode(determine_explaination("all"), ", ");
    tmp += implode(tmp2, "\n");
    tmp += "\n\n%^RESET%^Example: %^YELLOW%^explain "+tmp2[0]+"%^RESET%^ to have the mass explain "+tmp2[0]+"\n\n"+
    "Alternatively you can just type %^YELLOW%^explain%^RESET%^ or %^YELLOW%^ask%^RESET%^ to continue "+
    "on with the tutorial.%^RESET%^\n\n";
    tmp += "%^B_CYAN%^%^YELLOW%^NOTE: You MUST complete all the quests that the mass assigns to you, BEFORE "+
    "you are able to advance to level 6.%^RESET%^";
    return tmp;
}

void create()
{
    ::create();
    set_name("a strange brilliant mass");

    set_long((:TO, "myLong":));

    set_short("%^BOLD%^%^YELLOW%^A strange brilliant mass%^RESET%^");
    set_id(({"strange mass", "mass", "brilliant mass", "strange brilliant mass", "newbiemassobject"}));

    set_property("no animate", 1);
    set_property("soulbound", 1);
    set_property("no drop", 1);
    set_property("death keep", 1);

    set_weight(0);
    set_value(0);

    myTask = 1;
    myPlace = 1;
    myAlign = 0;
    myTimer = 0;
    explained = ({});
}

void init()
{
    ::init();
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(!living(ETO)) return;
    if((int)ETO->query_lowest_level() > 10 && living(ETO) && !avatarp(ETO))
    {
        tell_object(ETO, "%^BOLD%^%^YELLOW%^\n\nThe mass crumbles into nothingness and you "+
        "watch as the debris blow away!%^RESET%^");
        if(objectp(TO)) TO->remove();
        return;
    }
    if(!stringp(belongsTo))
    {
        if(userp(ETO))
        {
            belongsTo = ETOQN;
            call_out("introduce_me",8,ETO);
        }
    }
    if((string)ETOQN == belongsTo)
    {
        add_action("ask_act", "ask");
        add_action("feed_act", "feed");
        add_action("explain_act", "explain");
        return;
    }
}

void check_intro()
{
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(!userp(ETO)) return;
    if(myTask == 1 && myPlace == 1)
    {
        if(myTimer >= 10)
        {
            myTimer = 0;
            call_out("introduce_me", 8, ETO);
            return;
        }
        else
        {
            myTimer++;
            call_out("check_intro", 10);
            return;
        }
    }
}

int introduce_me(object targ)
{
    if(!objectp(TO)) return 0;
    if(!objectp(targ)) return 0;
    if(myTask != 1 && myPlace != 1) return 0;
    tell_object(targ, "%^RESET%^%^CYAN%^\nA strange whisper fills your ears:%^RESET%^ you... yeah you... psst, down here!");
    tell_object(targ, "%^RESET%^%^CYAN%^\nThe whispering continues, somewhat annoyed:%^RESET%^ down here!! In your inventory!! "+
    "I'm quick and sneaky, so you didn't even realize I was here, did ya? DON'T lie! Well, anyway I am the %^YELLOW%^"+
    "mass%^RESET%^ that is now in your inventory, SURPRISE!");
    tell_object(targ, "\n%^RESET%^%^CYAN%^The whispering seems amused now:%^RESET%^ I know, I know, it's not traditional... "+
    "typically the things in your inventory won't talk to you... but hey I'm not typical! Aaaannnnnddddd I have some %^BOLD%^"+
    "%^CYAN%^tasks%^RESET%^ for you. When you're adjusted and ready, simply %^YELLOW%^ask tasks%^RESET%^... but don't keep me "+
    "waiting too long.");
    check_intro();
    return 1;
}

void no_mention()
{
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    tell_object(ETO, "\n%^RESET%^%^CYAN%^The whispering seems quite amused:%^RESET%^ well, well, well since you didn't mention "+
    "tasks I am going to assume that you MEANT tasks!");
}

void introduce_task()
{
    string *tmp, myClass, *tmpquests;
    string WE = "%^RESET%^%^CYAN%^The strange whispering continues:%^RESET%^";
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    switch(myTask)
    {
        case 1:
            if(myPlace == 1) myPlace = 2;
            switch(myPlace)
            {
                case 2:
                    tell_object(ETO, "\n"+WE+" The first task is an important one. "+
                    "But before we get into it, there are some things that you need to know about this world. The first thing "+
                    "shows some information about yourself. It is in the form of the %^YELLOW%^bio%^RESET%^ command. "+
                    "When you are ready simply %^YELLOW%^explain bio%^RESET%^ and we will go from there.%^RESET%^");
                    break;
                case 3:
                    tell_object(ETO, "\n"+WE+" There is a "+
                    "meadow north of Offestry. You must venture into that meadow. Within the meadow you can %^YELLOW%^dig"+
                    "%^RESET%^.. you will learn that many areas allow custom actions for your character. You must dig "+
                    "until you find a particular black gem that was placed there specifically for you. Once you find that "+
                    "gem, you must return to the Offestry town square and then %^YELLOW%^feed%^RESET%^"+
                    " it to me. You may %^YELLOW%^explain my task%^RESET%^ if you need more information.%^RESET%^");
                    if(!stringp(ETO->query("NewbieMeadowRoom")))
                    {
                        tmp = get_dir("/d/newbie/rooms/meadow/*.c");
                        ETO->set("NewbieMeadowRoom", "/d/newbie/rooms/meadow/"+tmp[random(sizeof(tmp))]);
                    }
                    break;
            }
            break;
        case 2:
            switch(myPlace)
            {
                case 2:
                    tell_object(ETO, "\n"+WE+" The second task is an equally important one. "+
                    "But before we get into it, there are some other things that you need to know about yourself. As you gain "+
                    "experience you can advance in level at certain areas in the game. The town square of Offestry is one such area, so "+
                    "is the church.\n\n"+WE+" At certain levels you will be required to find a special trainer. Also, you will gain "+
                    "skill points as you level and every four levels you will gains a stat point, which can powerfully increase "+
                    "your character. When you are ready simply %^YELLOW%^explain stats%^RESET%^, %^YELLOW%^explain skills%^RESET%^, "+
                    "and %^YELLOW%^explain advance%^RESET%^.");
                    break;
                case 3:
                    if(member_array("Sirith's Task",TP->query_quests()) != -1)
                    {
                        tell_object(ETO, "\n"+WE+" It would seem that you have already completed the task that I had "+
                        "for you. Let us continue onward!");
                        advance_task();
                        return;
                        break;
                    }
                    tell_object(ETO, "\n"+WE+" There is a graveyard east of Offestry. Go there and before you enter it "+
                    "you will find a curious man who you can interact with. He will require a task from you that requires "+
                    "retrieval of an item from the graveyard. Retrieve this item and either complete the task as "+
                    "he demands or return to the Offestry town square then %^YELLOW%^feed%^RESET%^ the item to "+
                    "me. This will be your first introduction to the idea that completing one thing will forgo another. You "+
                    "may explain %^YELLOW%^explain my task%^RESET%^ if you need more information.%^RESET%^");
                    break;
            }
            break;
        case 3:
            switch(myPlace)
            {
                case 2:
                    tell_object(ETO, "\n"+WE+" The third task is an equally important one as well. "+
                    "However, before we get to that. There are some other things that you need to know about "+
                    "yourself, your equipment, and moving around. First off, you will get hungry and thirsty on "+
                    "Shadowgate. If you do not eat or drink, you can die, slowly and painfully.... \n\n"+WE+
                    " Your equipment, it can and will break. Eventually it will be useless to you, however, most "+
                    "merchants have the ability to repair any item that they will also buy. Also, as you explore "+
                    "the world you will learn that there are many ways of moving around.\n\n"+WE+" When "+
                    "you are ready to continue just %^YELLOW%^explain hunger%^RESET%^ or %^YELLOW%^explain thirst%^RESET%^, "+
                    "%^YELLOW%^explain repair%^RESET%^, and %^YELLOW%^explain movement%^RESET%^");
                    break;
                case 3:
                    if(member_array("Found the Staff of Davros",ETO->query_quests()) != -1)
                    {
                        tell_object(ETO, "\n"+WE+" It would seem that you have already completed the task "+
                        "that I had for you. Let us continue onward!");
                        advance_task();
                        return;
                        break;
                    }
                    tell_object(ETO, "\n"+WE+" There is a keep west of Offestry. Go there and before you enter it "+
                    "you will meet a woman, who is in distress. Look her over, interact with her, and find out what task "+
                    "she has for you.\n\n"+WE+" She too will require that you retrieve an item for her, though her "+
                    "task is much more in depth. When you have the item, either complete her task as she "+
                    "requires or return to the town square of Offestry and %^YELLOW%^feed%^RESET%^ it to me.\n\n"+WE+
                    " Remember, that some would consider feeding strange masses objects an %^RED%^evil"+
                    "%^RESET%^ action.");
                    break;
            }
            break;
        case 4:
            //fence information for thieves/bards
            if(!ETO->is_class("thief") && !ETO->is_class("bard"))
            {
                advance_task();
                return;
                break;
            }
            if(ETO->is_class("thief")) myClass = "thief";
            else myClass = "bard";
            switch(myPlace)
            {
                case 2:
                    tell_object(ETO, "\n"+WE+" As a "+myClass+" there are special hidden merchants available to you. "+
                    "They are called fences. They will launder any coins or any items of value that you "+
                    "%^YELLOW%^steal%^RESET%^ from unsuspecting others.\n\n"+WE+" I do not have a task for you related "+
                    "to them but I do wish to explain some of their functionality. When you are ready simply "+
                    "%^YELLOW%^explain fence%^RESET%^ and %^YELLOW%^explain guilds.%^RESET%^");
                    return;
                    break;
                case 3:
                    advance_task();
                    break;
            }
            break;
        case 5:
            switch(myPlace)
            {
                case 2:
                    tell_object(ETO, "\n"+WE+" I have one more task for you. But before we get to it I want to "+
                    "explain a few more concepts to you. First off, as you explore the world you will "+
                    "encounter some areas that are considered quest areas.\n\n"+WE+" Also, our world is "+
                    "large, sometimes you will not see other players for spans of time, but there is a command "+
                    "that can help you with.\n\n"+WE+" Finally, as you go into the world you will assume the "+
                    "role of your character, its attributes, skills, and ambitions. You should leave "+
                    "those of your own behind.\n\n"+WE+" When you are ready to continue simply "+
                    "%^YELLOW%^explain quest areas%^RESET%^, %^YELLOW%^explain rumors%^RESET%^, and "+
                    "%^YELLOW%^explain roleplay.%^RESET%^");
                    break;
                case 3:
                    tmpquests = ETO->query_mini_quests();
                    if(member_array("%^BOLD%^%^CYAN%^Newbie Quest: %^BOLD%^%^RED%^Killed the Gnome Leader!%^RESET%^", tmpquests) != -1 ||
                    member_array("%^BOLD%^%^CYAN%^Newbie Quest: %^BOLD%^%^RED%^Killed the Kobold Leader!%^RESET%^", tmpquests) != -1)
                    {
                        tell_object(ETO, "\n"+WE+" It would seem that you have already completed the task "+
                        "that I had for you. Let us continue onward!");
                        advance_task();
                        return;
                        break;
                    }
                    tell_object(ETO, "\n"+WE+" South of Offestry there are two systems of caverns. "+
                    "In one system there lives some friendly gnomes. Recently they have elected "+
                    "one as their leader.\n\n"+WE+" In the other cavern lives some hostile kobolds and "+
                    "hobgoblins, they too have recently installed a leader.. by quite different means.\n\n"+WE+" You are "+
                    "to find the leader of either the gnomes or the kobolds and slay it.\n\n"+WE+" Remember "+
                    "your alignment and the concept of roleplaying when you make your decision. A good "+
                    "aligned character will most likely prefer to see the kobolds defeated, where as an "+
                    "evil aligned character will most likely prefer to see the gnomes suffer.");
                    break;
            }
            break;
        default:
            switch(myPlace)
            {
                case 2:
                    tell_object(ETO, "\n"+WE+" You have completed all of the tasks that I have for you "+
                    "now there is just a little more information that you must be made aware of. \n\n"+
                    WE+" When you are ready %^YELLOW%^explain church%^RESET%^, %^YELLOW%^explain "+
                    "description%^RESET%^, and %^YELLOW%^explain adjective%^RESET%^.\n");
                    break;
                case 3:
                    if(newbiep(ETO))
                    {
                        tell_object(ETO, "\n"+WE+" Very well, I believe that you are ready. When you are ready "+
                        "for your final step before being moved into the greater world of Shadowgate "+
                        "%^YELLOW%^explain enter the world%^RESET%^\n");
                    }
                    else
                    {
                        tell_object(ETO, "\n"+WE+" You have completed all the tasks I have for you. I will remain "+
                        "with you in case you need for me to %^YELLOW%^explain%^RESET%^ something else until "+
                        "you reach level 10.%^RESET%^");
                    }
                    break;
            }
            break;
    }
}

varargs string determine_explaination(string which)
{
    if(!objectp(TO)) return "";
    if(!objectp(ETO)) return "";
    if(stringp(which))
    {
        if(myTask >= 1) which = "bio, ";
        if(myTask >= 2) which += "skills, stats, advance, ";
        if(myTask >= 3) which += "thirst, hunger, repair, movement, ";
        if(myTask >= 4 && (ETO->is_class("thief") || ETO->is_class("rogue"))) which += "fence, guilds, ";
        if(myTask >= 5) which += "rumors, quest areas, roleplay, ";
        if(myTask >= 6) which += "church, description, adjective, ";
        if(myPlace == 3)
        {
            if(myTask >= 6 && strsrch(base_name(EETO), "/d/newbie") != -1) which += "enter the world, ";
            return which += "my task, ";
        }
        else return which;
    }
    switch(myTask)
    {
        case 1:
            if(member_array("bio", explained) == -1) return "bio";
            else return "my task";
            break;
        case 2:
            if(member_array("skills", explained) == -1) return "skills";
            else if(member_array("stats", explained) == -1) return "stats";
            else if(member_array("advance", explained) == -1) return "advance";
            else return "my task";
            break;
        case 3:
            if(member_array("thirst", explained) == -1) return "thirst";
            else if(member_array("repair", explained) == -1) return "repair";
            else if(member_array("movement", explained) == -1) return "movement";
            else return "my task";
            break;
        case 4:
            if(member_array("fence", explained) == -1) return "fence";
            else if(member_array("guilds", explained) == -1) return "guilds";
            else return "my task";
            break;
        case 5:
            if(member_array("rumors", explained) == -1) return "rumors";
            else if(member_array("quest areas", explained) == -1) return "quest areas";
            else if(member_array("roleplay", explained) == -1) return "roleplay";
            else return "my task";
            break;
        default:
            if(member_array("church", explained) == -1) return "church";
            else if(member_array("description", explained) == -1) return "description";
            else if(member_array("adjective", explained) == -1) return "adjective";
            else if(member_array("enter the world", explained) == -1) return "enter the world";
            else return "my task";
    }
}


int explain_act(string str)
{
    int flag;
    object myRoom;
    string WE = "%^RESET%^%^CYAN%^The strange whispering explains:%^RESET%^";
    if(!objectp(TO)) return 0;
    if(!objectp(ETO)) return 0;
    if(!stringp(str)) flag = 1;
    if(!str) flag = 1;
    if(flag) str = determine_explaination();

    if(strsrch(str, "bio") != -1)
    {
        tell_object(ETO, "\n"+WE+" The bio command "+
        "allows you to see various statistics about yourself, such as how many creatures you have "+
        "brought to death or how many times you have experienced death yourself. It also reminds you "+
        "of your birthday.... if you happen to forget.\n\nThe command also accepts arguments now, so "+
        "you can do bio quests to see which quests you have completed, if any. Currently this is "+
        "not likely to be that impressive of a list, but this will grow in time. You can do bio "+
        "deaths to see how many times you have stood before Lysara and which creatures sent you there. "+
        "You can also do bio kills to see which creatures you have sent to face Lysara.%^RESET%^");

        tell_object(ETO, "\n"+WE+" You may %^YELLOW%^explain my task%^RESET%^ to continue.%^RESET%^");

        if(member_array("bio", explained) == -1) explained += ({"bio"});
    }
    else if(strsrch(str, "skills") != -1 && myTask >= 2)
    {
        tell_object(ETO, "\n"+WE+" The skills command "+
        "shows you all skills that your character has. As you advance in levels "+
        "you will be able to increase these skills. \n\n"+WE+" The syntax to increase "+
        "your academics skill by 1 point, for example, is %^YELLOW%^skills add 1 to academics."+
        "\n\n"+WE+" The total amount of any particular "+
        "skill depends on your class.\n\n"+WE+" To determine which skills are 'class skills' "+
        "for your particular class, type %^YELLOW%^help "+ETO->query_class()+".\n\n"+WE+" Also, "+
        "%^YELLOW%^help skills%^RESET%^ will go a long way toward explaining the syntax associated "+
        "with the skills command.%^RESET%^");
        if(member_array("skills", explained) == -1) explained += ({"skills"});
    }
    else if(strsrch(str, "stats") != -1 && myTask >= 2)
    {
        tell_object(ETO, "\n"+WE+" The stats command "+
        "shows you the attributes associated with your character. Every four levels you will "+
        "receive an additional point to add to one of your stats as you see fit. If you have "+
        "any available points the stats command will inform you of them. Should you have available "+
        "points you can increase your strength, for example, with the syntax %^YELLOW%^stats "+
        "gain strength%^RESET%^.\n\n"+WE+" You should see %^YELLOW%^help "+ETO->query_class()+" " +
        "%^RESET%^if you need to be reminded of what the primary stat for your class is.\n\n"+
        WE+" You will also find that many things, including poisons, monster abilities, and even "+
        "your own equipment can temporarily %^BOLD%^%^CYAN%^increase%^RESET%^ or %^BOLD%^%^RED%^"+
        "decrease%^RESET%^ your stats in this world. You can read %^YELLOW%^help stats%^RESET%^ for a "+
        "more in depth understanding of the command.%^RESET%^");
        if(member_array("stats", explained) == -1) explained += ({"stats"});
    }
    else if(strsrch(str, "advance") != -1 && myTask >= 2)
    {
        tell_object(ETO, "\n"+WE+" The advance command is very important on Shadowgate. It is "+
        "what allows you to advance your character level, should you have enough experience.\n\n"+WE+
        " If you see a negative number or a number below zero in score next to Exp To Next - then you "+
        "are able to advance to the next level. However, you are only able to advance in certain rooms, such as "+
        "temples, churches, or rooms with a message board in them.\n\n"+WE+" Also, at certain levels you "+
        "will be required to find a special trainer who can instruct you on how to advance. This is intended "+
        "to encourage you to explore the world of Shadowgate.\n\n"+WE+" You may read %^YELLOW%^help advance"+
        "%^RESET%^ to get more information and to find a brief hint about the location of this special trainer "+
        "should you require one to advance beyond your current level.%^RESET%^");
        if(member_array("advance", explained) == -1) explained += ({"advance"});
    }
    else if((strsrch(str, "hunger") != -1 && myTask >= 3) ||
    (strsrch(str, "thirst") != -1 && myTask >= 3))
    {
        tell_object(ETO, "\n"+WE+" You will grow hungry and thirsty as you travel the realm. You must "+
        "keep this in mind, otherwise you WILL die a slow and painful death.\n\n"+WE+" Thankfully there are "+
        "many ways to alleviate this. You can purchase food or drink from a variety of Inns or Taverns across the world. "+
        "You can also purchase rations and water skins from some general store merchants. The water skins "+
        "are able to be refilled. \n\n"+WE+" You may also find that in certain areas of the world food grows naturally. "+
        "Much like the %^YELLOW%^dig%^RESET%^ command that is available in the meadow that you went to before, these "+
        "commands might vary by the area. You can usually %^YELLOW%^search%^RESET%^ to get some hint of syntax. \n\n"+WE+
        " Also, if you are trained enough in the survival skill, you can attempt to %^YELLOW%^hunt%^RESET%^ "+
        "in certain areas of the world.\n\n"+WE+" Finally, there is some magic that has the ability to "+
        "stifle hunger and thirst or to sate it.\n\n"+WE+" The %^YELLOW%^score%^RESET%^ command and the "+
        "%^YELLOW%^hp%^RESET%^ commands both list your hunger and thirst levels, as they approach %^RED%^"+
        "red%^RESET%^ you will take damage.");
        if(member_array("thirst", explained) == -1) explained += ({"thirst"});
    }
    else if(strsrch(str, "repair") != -1 && myTask >= 3)
    {
        tell_object(ETO, "\n"+WE+" Your equipment will take damage from use, when you die, and when it is "+
        "damaged by others in combat. Eventually it will become worthless and provide no benefits to you. \n\n"+WE+
        " Thankfully most merchants throughout the world are able to repair equipment that they would also "+
        "buy from you. \n\n"+WE+" Keep in mind, however, that it will cost you gold to have them repair it. Also, "+
        "as you become more powerful and the equipment "+
        "that you possess also becomes more powerful then this will cost more gold and more gold, until it may "+
        "be easier to replace the equipment than to repair it.\n\n"+WE+" When in the room with a merchant you can "+
        "simply have the merchant %^YELLOW%^repair item%^RESET%^ and it will be done, as long as you "+
        "have the required amount of gold.");
        if(member_array("repair", explained) == -1) explained += ({"repair"});
    }
    else if(strsrch(str, "movement") != -1 && myTask >= 3)
    {
        tell_object(ETO, "\n"+WE+" You are already familiar with the standard ways of moving about the world. "+
        "This typical is as simple as entering the exit name - such as 'east' and then hitting enter. \n\n"+WE+
        " However, as you explore the world you will find that there is much more to it than this. There are "+
        "boats to travel vast oceans, ferries to travel short trips via river that would otherwise "+
        "take longer on foot. \n\n"+WE+" There are even mounts that you can learn to ride, if your %^YELLOW%^"+
        "athletics%^RESET%^ skill is high enough, that will alleviate some of the fatigue that you will suffer "+
        "from moving. \n\n"+WE+" There are magical portals, that sometimes work like normal exits, magical doors, spells, "+
        "magicl items, and even hidden exits through the world.\n\n"+WE+" Sometimes you must carefully %^YELLOW%^"+
        "search%^RESET%^ areas and struggle with syntax, but movement on Shadowgate can be complex and all of it "+
        "will affect your stamina. \n\n"+WE+" Your stamina is available on the %^YELLOW%^score%^RESET%^ or "+
        "%^YELLOW%^hp%^RESET%^ commands and thankfully simply taking a few moments to rest will usually be enough "+
        "for you to recover.%^RESET%^");
        if(member_array("movement", explained) == -1) explained += ({"movement"});
    }

    else if(strsrch(str, "fence") != -1 && myTask >= 4 && (ETO->is_class("thief") || ETO->is_class("bard")))
    {
        tell_object(ETO, "\n"+WE+" There are several fences through the world that are hidden in "+
        "thieves guilds. Their location is largely a mystery on purpose... so that the authorities cannot "+
        "shut them down, for example. \n\n"+WE+" If you have a high enough %^YELLOW%^thievery%^RESET%^ "+
        "skill and are able to steal items or pickpocket money from creatures or people in the world you can "+
        "%^YELLOW%^fence the items%^RESET%^ or %^YELLOW%^launder the money%^RESET%^ in such a location.\n\n"+WE+
        " Laundering money or fencing an item will reward account credits which will remain at the fence and "+
        "allow you to purchase items from it and also reward a small amount of experience, depending on the difficulty "+
        "of the involved theft.");
        if(member_array("fence", explained) == -1) explained += ({"fence"});
    }
    else if(strsrch(str, "guilds") != -1 && myTask >= 4 && (ETO->is_class("thief") || ETO->is_class("bard")))
    {
        tell_object(ETO, "\n"+WE+" There are several well established thieves guilds throughout the realm. "+
        "However, their locations are usually hidden for all but the most inquisitive and quite intentionally. \n\n"+
        WE+" There is one such guild located in the town of Offestry... It is in the otherwise normal looking bar. "+
        "If you remember the explanation that I offered about movement you will remember that sometimes there are "+
        "hidden exits. (%^YELLOW%^explain movements%^RESET%^) \n\n"+WE+" Go there now if you are curious "+
        "and pay close attention to the curtain.%^RESET%^");
        if(member_array("guilds", explained) == -1) explained += ({"guilds"});
    }
    else if(strsrch(str, "quest areas") != -1 && myTask >= 5)
    {
        tell_object(ETO, "\n"+WE+" Throughout the world there are many areas which are considered quest areas. "+
        "Sometimes you will know them before entering and other times you will not realize that they are quest "+
        "areas until you are inside.\n\n"+WE+" A good majority of them will require that you complete some task or "+
        "quest in order to leave, they will even block magic from allowing you to escape. There are some exceptions to "+
        "this rule and some areas will even have hidden quests.\n\n"+WE+" Keep in mind that when venturing into these "+
        "areas with other people you try to never give away any secrets. Let others discover what the world has hidden on "+
        "their own. When in doubt feel free to ask someone over %^BOLD%^%^MAGENTA%^ooc%^RESET%^ or other lines.%^RESET%^");
        if(member_array("quest areas", explained) == -1) explained += ({"quest areas"});
    }
    else if(strsrch(str, "rumors") != -1 && myTask >= 5)
    {
        tell_object(ETO, "\n"+WE+" The world of Shadowgate is large and it expands frequently as new areas are "+
        "discovered. To help with this, there exists a %^YELLOW%^rumors%^RESET%^ command.\n\n"+WE+" This command "+
        "will give you a hint of areas that you can explore on your own or within a party, or areas which might have "+
        "quests for you to attempt.\n\n"+WE+" The rumors command will also allow you to see some areas where "+
        "other players might have previously been, should you want to seek them out for interaction.");
        if(member_array("rumors", explained) == -1) explained += ({"rumors"});
    }
    else if(strsrch(str, "rolepla") != -1 && myTask >= 5)
    {
        tell_object(ETO, "\n"+WE+" You are "+capitalize(ETOQN)+" now. You are not the person behind the "+
        "keyboard in the world of Shadowgate. Your actions, your ambitions, your motivations are dictated "+
        "now by your statistics, your skills, your feats, your deity, your class, your alignment, and more.\n\n"+WE+" It is "+
        "important to remember this so that you will respond appropriately when you are exploring the world, "+
        "interacting with other players, and even sitting in a tavern to enjoy a meal between adventures.\n\n"+WE+
        " It is a subjective art and some have different perspectives on it, but remember our setting - which is "+
        "mostly dungeons and dragons forgotten realms - with a lot of custom content - and you may very well "+
        "learn to love the experience.\n\n"+WE+" In time you may even become a High Mortal, one of those "+
        "known throughout the realm for one reason or another, but respected by all because of their "+
        "unique ability to play their character so well as to seem alive.");
        if(member_array("roleplay", explained) == -1) explained += ({"roleplay"});
    }
    else if(strsrch(str, "church") != -1 && myTask >= 6)
    {
        tell_object(ETO, "\n"+WE+" Churches and temples are very important in the world of Shadowgate. "+
        "You may have already used them to %^YELLOW%^advance%^RESET%^ or return to them when "+
        "you have died and met Kelemvor.\n\n"+WE+" However, they serve other important purposes. From "+
        "within a church or temple you can %^YELLOW%^read sign%^RESET%^ to get more information. \n\n"+WE+
        " From within a temple you can %^YELLOW%^read charge%^RESET%^ to get information about the specific "+
        "deity of that temple. \n\n"+WE+" One very important ability that is available within a church or "+
        "temple is %^YELLOW%^identify curse on <object>%^RESET%^. This is important because as you find equipment "+
        "in the world of Shadowgate, a lot of it will be magically enchanted. \n\n"+WE+" Sometimes this enchantment "+
        "will be %^RED%^cursed%^RESET%^ and if you equip such equipment it will cost much gold for you to "+
        "remove it. \n\n"+WE+" Always remember this when finding something new that looks interesting, less "+
        "you find yourself cursed.%^RESET%^");
        if(member_array("church", explained) == -1) explained += ({"church"});
    }
    else if(strsrch(str, "description") != -1 && myTask >= 6)
    {
        tell_object(ETO, "\n"+WE+" Your description is what other players will see when looking you over. If "+
        "you have not already you should read %^YELLOW%^help describe%^RESET%^. \n\n"+WE+" Keep in mind that "+
        "you need to set a description that adequately conveys to other players what your character looks like. "+
        "You must do this before leaving the newbie area - in just a few moments - if you have not already. \n\n"+WE+
        " Your description should also consider your statistics available via the %^YELLOW%^stats%^RESET%^ "+
        "command.%^RESET%^");
        if(member_array("description", explained) == -1) explained += ({"description"});
    }
    else if(strsrch(str, "adjective") != -1 && myTask >= 6)
    {
        tell_object(ETO, "\n"+WE+" Your adjective is what other players will see when they first encouter you in "+
        "a room or when they use the %^YELLOW%^who%^RESET%^ command. If you have not already you should read "+
        "%^YELLOW%^help adjective%^RESET%^. \n\n"+WE+" Keep in mind that you should set an adequate adjective so "+
        "that to give other players an idea of what you briefly look like when they first encounter you. You must do "+
        "this before leaving the newbie area - in just a few moments - if you have not already.");
        if(member_array("adjective", explained) == -1) explained += ({"adjective"});
    }
    else if(strsrch(str, "enter the world") != -1 && myTask >= 6 &&
    strsrch(base_name(EETO), "/d/newbie") != -1 &&
    strsrch(base_name(EETO), "/d/newbie/ooc/trainer") == -1)
    {
        tell_object(ETO, "\n%^BOLD%^%^WHITE%^You feel the world around you "+
        "shifting and changing as you suddenly find yourself somewhere "+
        "else!%^RESET%^");
        tell_room(EETO, ETOQCN+"%^BOLD%^%^WHITE%^ suddenly shifts and wavers "+
        "before blinking out of existence!", ETO);
        myRoom = new("/d/newbie/ooc/trainer");
        myRoom->set_for(ETO);
        ETO->move_player(myRoom);
        return 1;
    }
    else if(strsrch(str, "my task") != -1)
    {
        if(myPlace != 3)
        {
            switch(myTask)
            {
                case 1:
                if(member_array("bio", explained) != -1 && strsrch(str, "my task") != -1)
                {
                    myPlace = 3;
                    introduce_task();
                }
                break;
            case 2:
                if(member_array("stats", explained) != -1 && member_array("skills", explained) != -1 &&
                member_array("advance", explained) != -1 && strsrch(str, "my task") != -1)
                {
                    myPlace = 3;
                    introduce_task();
                }
                break;
            case 3:
                if(member_array("movement", explained) != -1 && member_array("thirst", explained) != -1 &&
                member_array("repair", explained) != -1 && strsrch(str, "my task") != -1)
                {
                    myPlace = 3;
                    introduce_task();
                }
                break;
            case 4:
                if(member_array("fence", explained) != -1 && member_array("guilds", explained) != -1 &&
                strsrch(str, "my task") != -1)
                {
                    myPlace = 3;
                    introduce_task();
                }
                break;
            case 5:
                if(member_array("rumors", explained) != -1 && member_array("roleplay", explained) != -1 &&
                member_array("quest areas", explained) != -1 && strsrch(str, "my task") != -1)
                {
                    myPlace = 3;
                    introduce_task();
                }
                break;
            default:
                if(member_array("description", explained) != -1 && member_array("church", explained) != -1 &&
                member_array("adjective", explained) != -1 && strsrch(str, "my task") != -1)
                {
                    myPlace = 3;
                    introduce_task();
                }
            }
            return 1;
        }
        switch(myTask)
        {
            case 1:
                tell_object(ETO, "\n"+WE+" Your current "+
                "task is to enter the meadow north of Offestry.\n\n"+WE+" Once inside "+
                "that meadow, you are able to %^YELLOW%^dig%^RESET%^. This is a custom "+
                "action allowed within the meadow.\n\n"+WE+" Many areas within the game "+
                "allow for custom actions as you will learn in time.\n\n"+WE+" Within the meadow "+
                "there is a black gem that has been buried there specifically for you and you "+
                "alone to %^YELLOW%^dig%^RESET%^ up. Once you find it, return to the offestry town square, then "+
                "%^YELLOW%^feed%^RESET%^ it to me. I will absorb "+
                "its power and then we can continue on with more tasks.%^RESET%^");
                break;
            case 2:
                tell_object(ETO, "\n"+WE+" Your current "+
                "task is to go to the graveyard east of Offestry.\n\n"+WE+" Near there you "+
                "will encounter a man, look him over, interact with him, and learn what "+
                "task he would have you complete.\n\n"+WE+" He will want you to retrieve an "+
                "item for him. \n\n"+WE+" You may either complete "+
                "the task as he requests or return to the Offestry town square and %^YELLOW%^feed "+
                "%^RESET%^the item to me. You cannot do both and this will be your first "+
                "foray into understanding that in this world making one decision will sometimes prevent "+
                "you from making another.\n\n"+WE+" Some would tell you that feeding things to "+
                "strange masses is an %^RED%^evil%^RESET%^ action, so keep this in mind.");
                break;
            case 3:
                tell_object(ETO, "\n"+WE+" Your current task is to go to the "+
                "keep west of Offestry.\n\n"+WE+" Near there you will encounter a distraught woman, "+
                "named Jessa. Look her over, interact with her, and learn what task she would have you "+
                "complete.\n\n"+WE+" She will require that you retrieve an item for her. \n\n"+WE+" However, "+
                "this task will be more complex than the others thus far. Once you have the item, "+
                "you may complete her task as required or return to the Offestry town square and "+
                "%^YELLOW%^feed%^RESET%^ the item to me. \n\n"+WE+" Remember that feeding things to "+
                "strange masses is likely an %^RED%^evil%^RESET%^ action.");
                break;
            case 4:
                advance_task();
                break;
            case 5:
                tell_object(ETO, "\n"+WE+" Your current task is to go to the caverns "+
                "south of Offestry.\n\n"+WE+" There are two caverns there, within one live some peaceful "+
                "gnomes.\n\n"+WE+" Within the other lives some hostile kobolds and hobgoblins.\n\n"+WE+
                " Both have recently elected a leader. Your task is to slay one or the other, either the "+
                "leader of the gnomes or the leader of the kobolds.\n\n"+WE+" Neither task will be easy... "+
                "and you should remember your alignment when making your choice. \n\n"+WE+" A good "+
                "aligned character would most likely prefer to see the kobolds defeated. \n\n"+WE+
                " An evil aligned character may prefer to see the gnomes suffer.\n\n"+WE+" When this "+
                "task is completed there will be only one more thing required from you and then you shall "+
                "venture forth into the wide world, your destiny awaits!%^RESET%^");
                break;
            default:
                if(base_name(EETO) == "/d/newbie/rooms/trainer" && strsrch(base_name(EETO), "/d/newbie/") == -1)
                {
                    tell_object(ETO, "\n"+WE+" I cannot explain that right now. You may %^YELLOW%^ask tasks"+
                    "%^RESET%^ in order to determine what I can explain.");
                    break;
                }
                tell_object(ETO, "\n"+WE+" Your current task is simply to %^YELLOW%^explain "+
                "enter the world%^RESET%^ this will move you into a specialized "+
                "trainer, that is set up specifically for you. \n\n"+WE+" Much like what you will "+
                "eventually have to find in the larger world of Shadowgate. Keep in mind that "+
                "you will have to find these trainers every 5 levels as a way to encourage "+
                "exploration once you are in the larger world.%^RESET%^");
                break;
        }
    }
    else
    {
        tell_object(ETO, "\n"+WE+" I cannot explain that right now. You may %^YELLOW%^ask tasks"+
        "%^RESET%^ in order to determine what I can explain.");
    }

    return 1;
}

int ask_act(string str)
{
    if(!objectp(TO)) return 0;
    if(!objectp(ETO)) return 0;
    if(!stringp(str))
    {
        no_mention();
        introduce_task();
    }
    else if(stringp(str))
    {
        if(strsrch(str, "task") != -1)
        {
            introduce_task();
        }
        else
        {
            no_mention();
            introduce_task();
        }
    }
    else
    {
        no_mention();
        introduce_task();
    }
    return 1;
}

void advance_task()
{
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    switch(myTask)
    {
        case 1:
            NEWB_D->spawn_eq(ETO, myTask);
            myTask++;
            break;
        case 2:
            NEWB_D->spawn_eq(ETO, myTask);
            myTask++;
            break;
        case 3:
            NEWB_D->spawn_eq(ETO, myTask);
            myTask++;
            break;
        case 4:
            myTask++;
            break;
        case 5:
            NEWB_D->spawn_eq(ETO, myTask);
            myTask++;
            break;
        default:
            if(myTask < 6) myTask ++;
            break;
            //remove object;
    }
    if(objectp(TO))
    {
        if(myTask < 7) myPlace = 2;
        if(newbiep(ETO)) NEWB_D->advance_level(ETO);
        if(myTask == 6)
        {
            while((int)ETO->query_lowest_level() < 5)
            {
                NEWB_D->advance_level(ETO);
            }
        }
        introduce_task();
        return;
    }
}

void adjust_my_align(int x)
{
    myAlign += x;
}

int query_myAlign() { return myAlign; }

int feed_act(string str)
{
    object myOb;
    if(!objectp(TO)) return 0;
    if(!objectp(ETO)) return 0;
    if(!objectp(EETO)) return 0;
    if(base_name(EETO) != "/d/newbie/rooms/town/square")
    {
        tell_object(ETO,"You must be by the board at Offestry Town square if you ment to %^YELLOW%^feed%^RESET%^ me.");
        return 0;
    }
    switch(myTask)
    {
        case 1:
            if(objectp(myOb = present("newbiemeadowob", ETO)))
            {
                tell_object(ETO,"\n%^YELLOW%^The strange mass absorbs the black gem "+
                "and begins mutating... ");
                tell_object(ETO,"\n%^RESET%^%^CYAN%^The strange whispering continues excitedly: "+
                "Yes, I shall use the power of the gem to grow! You will come to learn that "+
                "sometimes in the world there are decisions to be made. Meaning that doing "+
                "one thing will prevent you from doing another... or perhaps helping someone will "+
                "cause someone else to hate you.");
                myOb->remove();
                if(ETO->query("NewbieMeadowRoom")) ETO->delete("NewbieMeadowRoom");
                advance_task();
                return 1;
                break;
            }
            tell_object(ETO, "\n%^YELLOW%^The strange mass doesn't seem interested in that.%^RESET%^");
            return 1;
            break;
        case 2:
            if(objectp(myOb = present("myringz", ETO)))
            {
                tell_object(ETO,"\n%^YELLOW%^The strange mass absorbs the "+myOb->query_name()+" "
                "and seems to continue mutating....");
                tell_object(ETO, "\n\n%^RESET%^%^CYAN%^The strange whispering seems almost hoarse:%^RESET%^ " +
                "Yes, I shall use the power of the ring to grow even more powerful... recall that I warned you "+
                "that %^YELLOW%^feeding%^RESET%^ things to strange masses is considered by most to be an "+
                "%^RED%^evil%^RESET%^ action....");
                myOb->remove();
                myAlign -= (25 + random(25));
                ETO->set_quest("Ignored Sirith's Task");
                tell_object(ETO, "You have chosen to Ignore Sirith's Task!");
                "/cmds/avatar/_note.c"->cmd_note("add "+ETOQN+" retrieved the ring for Sirith and fed it to "+
                "the mass! (newbie quest).");
                advance_task();
                return 1;
                break;
            }
            tell_object(ETO, "\n%^YELLOW%^The strange mass doesn't seem interested in that.%^RESET%^");
            return 1;
            break;
        case 3:
            if(objectp(myOb = present("drakeclaw staff", ETO)))
            {
                tell_object(ETO,"\n%^YELLOW%^The strange mass absorbs the "+myOb->query_name()+" "
                "and seems to continue mutating....");
                tell_object(ETO, "\n\n%^RESET%^%^CYAN%^The strange whispering seems almost hoarse:%^RESET%^ " +
                "Yes, I shall use the power of the staff to grow even more powerful... recall that I warned you "+
                "that %^YELLOW%^feeding%^RESET%^ things to strange masses is considered by most to be an "+
                "%^RED%^evil%^RESET%^ action....");
                myOb->remove();
                myAlign -= (25 + random(25));
                ETO->set_quest("Found the staff of Davros but fed it to the mass");
                tell_object(ETO, "You have chosen to feed the Staff of Davros to the strange mass!");
                "/cmds/avatar/_note.c"->cmd_note("add "+ETOQN+" Found Davros' Staff and fed it to the strange mass!");
                advance_task();
                return 1;
                break;
            }
            tell_object(ETO, "\n%^YELLOW%^The strange mass doesn't seem interested in that.%^RESET%^");
            return 1;
        case 4:
            break;
    }
    return 0;
}

int query_myTask() { return myTask; }
