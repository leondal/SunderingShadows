#include <std.h>
#include <daemons.h>
#define NEWB_D "/d/newbie/ooc/newbie_d.c"

inherit "/std/quest_room.c";

string myPlayer;
object myTrainer;
int isSetup;
string *bad_races = ({"drow", "half-drow", "goblin", "hobgoblin", "kobold", "ogre", "half-ogre", "orc", "gnoll", "bugbear", "minotaur", "yuan-ti", "ratkin", "troll"});
string BAD;


int query_light()
{
    if(BAD) { return -1; }
    return 1;
}

void set_for(object who)
{
    if (!objectp(who)) {
        return;
    }
    if (!userp(who)) {
        return;
    }
    myTrainer = who;
    myPlayer = (string)who->query_name();
    set_player(myPlayer);
    if (member_array((string)who->query_race(), bad_races) != -1) {
        TO->add_exit("/d/shadow/room/muuldaan/rooms/cavern1", "portal");
        TO->set_light(-1);
        BAD = 1;
        isSetup = 1;
    }else {
        TO->add_exit("/d/darkwood/tabor/room/math4", "portal");
        TO->set_light(1);
        isSetup = 1;
    }
    set_pre_exit_functions(({ "portal" }), ({ "GoThroughDoor" }));
    return;
}

void create()
{
    ::create();

    set_short("The First Training Camp");
    set_long("%^BOLD%^%^WHITE%^Before you are able to "+
    "leave this room you must set a describe and an adjective. You must also "+
    "advance to non-newbie status, you should have enough experience now to do so.\n\n"+
    "You may see %^YELLOW%^help describe%^BOLD%^%^WHITE%^ and "+
    "%^YELLOW%^help adjective%^BOLD%^%^WHITE%^ to be reminded of "+
    "how each works. \n\nFurthemore, you may type %^YELLOW%^examples "+
    "describe%^BOLD%^%^WHITE%^ and %^YELLOW%^examples adjective "+
    "%^BOLD%^%^WHITE%^to see a couple of examples of both from real "+
    "Sundering Shadows players.\n%^RESET%^");
	set_smell("default","A pleasing aroma saturates the area.");
	set_listen("default","A stillness hangs over the area.");
	set_property("Specialist",1);
    set_property("no teleport",1);
        set_property("indoors",1);
	set_property("training",1);
    set_property("no sticks",1);
    set_property("no starve",1);
    set_property("no magic",1);
    set_property("no steal",1);
    set_travel(PAVED_ROAD);
    set_terrain(VILLAGE);
    //set_pre_exit_functions(({"out"}),({"GoThroughDoor"}));
	//set_light(2);
    isSetup = 0;
}

void init()
{
    ::init();
    add_action("example_act", "examples");
    if(!objectp(TO)) return;
    if(!objectp(TP)) return;
    if(userp(TP))
    {
//        if((string)TPQN == myPlayer)
//        {
            if(!objectp(myTrainer)) set_for(TP);
            else if(myTrainer != TP) set_for(TP);
//        }
    }
    return;
}

int GoThroughDoor()
{
    object tmp;
    if(!objectp(TP)) return 0;
    if(!stringp(TP->query_description()))
    {
        tell_object(TP, "%^BOLD%^%^WHITE%^You are required to set a describe "+
        "before you leave this room in pursuit of your destiny. \n\nPlease read "+
        "%^YELLOW%^help describe%^BOLD%^%^WHITE%^ if you need a reminder of how the "+
        "command to set your describe works. \n\nYou may also type "+
        "%^YELLOW%^examples describe%^BOLD%^%^WHITE%^ while in this room to "+
        "see some examples of real describess that Sundering Shadows players have set "+
        "for their characters.%^RESET%^");
        return 0;
    }
    if(!stringp(TP->getWholeDescriptivePhrase()))
    {
        tell_object(TP, "%^BOLD%^%^WHITE%^You are required to set an adjective "+
        "before you leave this room in pursuit of your destiny. \n\nPlease read "+
        "%^YELLOW%^help adjective%^BOLD%^%^WHITE%^ if you need a reminder of how the "+
        "command to set your adjective works. \n\nYou may also type "+
        "%^YELLOW%^examples adjective%^BOLD%^%^WHITE%^ while in this room to "+
        "see some examples of real adjectives that Sundering Shadows players have set "+
        "for their characters.%^RESET%^");
        return 0;
    }
    if(newbiep(TP))
    {
        tell_object(TP, "%^BOLD%^%^WHITE%^You must advance to non-newbie status "+
        "before you are able to leave this trainer. You should have enough experience "+
        "now in order to do so. You can do so by using the %^YELLOW%^advance"+
        "%^BOLD%^%^WHITE%^ command.%^RESET%^");
        return 0;
    }
    if((string)TPQN == myPlayer)
    {
        if(objectp(tmp = present("newbiemassobject", TP)))
        {
            if((int)tmp->query_myTask() >= 6) NEWB_D->spawn_eq(TP, 6, (int)tmp->query_myAlign());
            //remove mass? or keep mass around?
            //spawn helmet based on class
        }
        if((int)"/d/newbie/rooms/town/bank.c"->close("account", 1) == 1)
        {
            tell_object(TP, "\n\n%^BOLD%^%^CYAN%^You bank account in Offestry has "+
            "been closed and the funds transferred into your inventory. You can check "+
            "this with the %^BOLD%^%^YELLOW%^money%^BOLD%^%^CYAN%^ command.%^RESET%^");
        }

        if (USER_D->is_pk_race_player(TP)) {
            TP->delete("no pk");
            tell_object(TP, "%^YELLOW%^As a player of PK race, you are no longer flagged for PK immunity.%^RESET");
        }

        if(member_array((string)TP->query_race(), bad_races) == -1)
        {
            tell_object(TP, "\n\n%^BOLD%^%^CYAN%^A map of the town of tabor appears "+
            "in your inventory!%^RESET%^");
            new("/d/darkwood/tabor/obj/map.c")->move(TP);
            new("/d/common/obj/special/bloodshard")->move(TP);
            new("/d/common/obj/special/bloodshard")->move(TP);
            new("/d/common/obj/special/bloodshard")->move(TP);
        }

        tell_object(TP, "%^BOLD%^%^YELLOW%^\n\nYou are now entering the large world of "+
        "Sundering Shadows. There are many commands and help files that have not been covered by "+
        "this tutorial. \n\nFeel free to ask over the lines, particularly the %^CYAN%^<ooc>%^ORANGE%^ line, if "+
        "you find something that you do not understand. "+
        "\n\nThere are also nuances of the game that you will only learn in time and with "+
        "experience. A good many players who give the game time learn that they love it, "+
        "particularly the depth from the roleplay, but also the exploration and the "+
        "different mechanics.\n\nIt is our hope that you will become one of those players!\n\n"+
        "%^B_CYAN%^%^YELLOW%^Welcome to Sundering Shadows!%^RESET%^\n\n");
        //make map appear in inventory
        if(TP->query("advance place")) TP->set("advance place", 0);
        TP->move_player(TO->query_exit("portal"));
        if(objectp(TO)) TO->remove();
        return 0;
    }
    return 0;
}

int example_act(string str)
{
    if(!objectp(TO)) return 0;
    if(!objectp(TP)) return 0;
    if(!stringp(str))
    {
        tell_object(TP, "\nYou may see examples for "+
        "describes or adjectives. Please specify which one "+
        "you wish to see.\n");
        return 1;
    }
    if(strsrch(str, "describe") != -1)
    {
        switch(random(3))
        {
            case 0:
                tell_object(TP, "\n\n%^BOLD%^%^WHITE%^Describe Example 1:\n\n%^BOLD%^%^BLACK%^has long, silky, "+
                "deep %^RESET%^%^BLUE%^black %^BOLD%^%^BLACK%^hair "+
                "that looks as if it has the slightest hint of %^RESET%^%^MAGENTA%^"+
                "purple%^BOLD%^%^BLACK%^. Bangs cover most of her face. They look to "+
                "be hiding a %^RESET%^%^ORANGE%^scar %^BOLD%^%^BLACK%^under her "+
                "left eye. She's got a round face, deep %^RESET%^%^RED%^brown "+
                "%^BOLD%^%^BLACK%^eyes and a slight %^MAGENTA%^smile%^BLACK%^. She "+
                "has a rather friendly look about her. She is of average height "+
                "and a little plump. Her skin is %^RESET%^%^ORANGE%^tan %^BOLD%^"+
                "%^BLACK%^presumably from her time in the %^ORANGE%^sun%^BLACK%^. "+
                "Her arms are muscular. N%^RESET%^o %^BOLD%^%^BLACK%^doubt from the "+
                "%^RESET%^long sword %^BOLD%^%^BLACK%^and %^RESET%^%^CYAN%^shield %^BOLD%^"+
                "%^BLACK%^she carries with her.%^RESET%^%^MAGENTA%^");
                break;
            case 1:
                tell_object(TP, "\n\n%^BOLD%^%^WHITE%^Describe Example 2:\n\n%^BOLD%^%^BLACK%^is a slimly built, "+
                "tanned young man of above average height. %^RESET%^%^RED%^A%^ORANGE%^"+
                "u%^RED%^b%^ORANGE%^u%^RED%^r%^ORANGE%^n %^BOLD%^%^BLACK%^ "+
                "hair more red than brown falls over his forehead yet remains "+
                "cut short elsewhere%^RESET%^%^RED%^. %^BOLD%^%^BLACK%^The seemingly "+
                "random locks lying across his forehead serve to "+
                "frame his eyes, eyes the color of b%^RESET%^r%^BOLD%^%^BLACK%^"+
                "e%^RESET%^w%^BOLD%^%^BLACK%^i%^RESET%^n%^BOLD%^%^BLACK%^g "+
                "%^RESET%^s%^BOLD%^%^BLACK%^t%^RESET%^o%^BOLD%^%^BLACK%^r"+
                "%^RESET%^m %^BOLD%^%^BLACK%^c%^RESET%^l%^BOLD%^%^BLACK%^o"+
                "%^RESET%^u%^BOLD%^%^BLACK%^d%^RESET%^s%^BOLD%^%^BLACK%^. "+
                "Clean yet sharp lines define his facial features, though "+
                "they are disturbed by the short beard covering his chin. "+
                "Behind the beard a slim, %^WHITE%^white scar %^BLACK%^can "+
                "be spotted against his %^RESET%^%^ORANGE%^tan %^BOLD%^ "+
                "%^BLACK%^flesh. Running diagonally the scar is obviously old "+
                "and runs from high on the left down to the right between the "+
                "lines of his jaw. Whatever the rest of his body looks "+
                "like is hidden by the loosely fitting robe ending just above his "+
                "ankles. Stitched onto the right shoulder of his robe is a "+
                "%^RESET%^%^BLUE%^s%^BOLD%^%^WHITE%^p%^BLUE%^a%^WHITE%^"+
                "r%^RESET%^%^BLUE%^r%^BOLD%^%^WHITE%^o%^BLUE%^w%^WHITE%^h"+
                "%^RESET%^%^BLUE%^a%^BOLD%^%^WHITE%^w%^BLUE%^k %^BLACK%^done in a "+
                "mixture of blue and white threads. Appearing to be %^CYAN%^ "+
                "graceful %^BLACK%^in stillness the effect is ruined once he "+
                "moves by the pronounced %^RESET%^%^MAGENTA%^limp %^BOLD%^%^BLACK%^"+
                "evidenced in his stride.%^WHITE%^");
                break;
            case 2:
                tell_object(TP, "\n\n%^BOLD%^%^WHITE%^Describe Example 3:\n\n%^ORANGE%^is a massive %^BOLD%^"+
                "%^BLACK%^ebon skinned%^RESET%^%^ORANGE%^ man, with sharp "+
                "%^BOLD%^%^WHITE%^tusklike %^RESET%^%^ORANGE%^teeth which jut up "+
                "from his protruding lower jaw. His ears are large, pointed at the "+
                "tips and rather misshapen, with heavy lobes that flap when he moves "+
                "his head. His %^RESET%^b%^BOLD%^%^WHITE%^e%^RESET%^ady gray e%^BOLD%^"+
                "%^WHITE%^y%^RESET%^es %^ORANGE%^are small and sunken below his heavy "+
                "brow. His %^GREEN%^large head %^ORANGE%^is supported on a %^MAGENTA%^"+
                "thick neck%^ORANGE%^, and bowed, %^MAGENTA%^muscular arms %^ORANGE%^hang "+
                "from massive shoulders. Long fingers spring from hands the size of dinner "+
                "plates and bear thick, %^BOLD%^%^BLACK%^black%^RESET%^%^ORANGE%^, "+
                "%^BOLD%^%^BLACK%^clawlike %^RESET%^%^ORANGE%^nails. His legs, thick "+
                "as %^GREEN%^stumps%^ORANGE%^, are almost always bent, as is his back, "+
                "giving him a %^RESET%^hunched posture%^ORANGE%^ that still fails to "+
                "hide his massive size or obvious %^RESET%^half-ogre%^ORANGE%^ heritage.");
                break;
        }
        tell_object(TP, "\n\n%^BOLD%^%^WHITE%^It is important to note that each person is different. "+
        "The important thing is to have a describe that does not convey actions or "+
        "feelings.\n\nAlso an important note, which you may have noticed, "+
        "is that you do not need to add your name to your describe. In fact, your name if you are "+
        "recognized by someone is added to the front of it along with your adjective. If you are not "+
        "recognized by the person then only your adjective will appear in front of whatever you enter "+
        "as your describe.\n\nIt is also possible that as your equipment changes or things happen "+
        "to your character that your describe will change. Try to think of it as fluid and evolving "+
        "with your character.%^RESET%^");
        return 1;
    }
    if(strsrch(str, "adjective") != -1)
    {
        switch(random(3))
        {
            case 0:
                tell_object(TP, "\n\n%^BOLD%^%^WHITE%^Adjective Example 1:\n\n"+
                "%^BOLD%^$R %^MAGENTA%^fe%^RESET%^%^MAGENTA%^m%^BOLD%^a%^RESET%^%^MAGENTA%^l%^BOLD%^e "+
                "%^RESET%^with long %^BOLD%^%^BLACK%^bl%^RESET%^a%^BOLD%^%^BLACK%^ck h%^RESET%^a%^BOLD%^"+
                "%^BLACK%^ir, %^RESET%^%^RED%^b%^ORANGE%^r%^RED%^own e%^ORANGE%^y%^RED%^es %^WHITE%^and a "+
                "%^MAGENTA%^pl%^BOLD%^%^RED%^u%^RESET%^%^MAGENTA%^mp %^WHITE%^build.%^RESET%^");
                break;
            case 1:
                tell_object(TP, "\n\n%^BOLD%^%^WHITE%^Adjective Example 2:\n\n"+
                "%^RESET%^%^RED%^auburn haired%^RESET%^%^BLUE%^ $SR%^RESET%^%^CYAN%^ male "+
                "with%^RESET%^ %^BOLD%^%^BLACK%^dark grey eyes%^RESET%^");
                break;
            case 2:
                tell_object(TP, "\n\n%^BOLD%^%^WHITE%^Adjective Example 3:\n\n"+
                "%^BOLD%^%^BLACK%^$CSR%^RESET%^%^GREEN%^ $R %^ORANGE%^with %^RESET%^$E eyes "+
                "%^ORANGE%^and %^BOLD%^%^BLACK%^$H hair%^RESET%^");
                break;
        }
        tell_object(TP, "\n\n%^BOLD%^%^WHITE%^It is important to note that each person is different. "+
        "The important thing is to have an adjective that does not convey actions or feelings.\n\nAlso, "+
        "you may have noticed the characters such as $R (race) and $H (hair color) in the examples. "+
        "The %^YELLOW%^help adjective%^BOLD%^%^WHITE%^ explains these special characters and their purpose.");
        return 1;
    }
    return 0;
}
