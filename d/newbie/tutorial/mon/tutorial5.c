
#include <std.h>
inherit NPC;

void create() {
   ::create();
   set_name("humano");
   set_id(({"lean human","tutorial5", "man"}));
   set_short("A short and lean human with dark brown hair");
   set_long("This short and lean human has dark brown hair and mischevious green eyes. "+
   "He watches you intently, as if he is waiting for you to do something.");
   set_alignment(5);
   set_race("human");
   set_class("fighter");
   set_body_type("human");
   set_property("no attack",1);
   set_hd(25,1);
   set_max_hp(800);
   set_hp(800);
   set_gender("male");
}

void init() {
   ::init();
   call_out("step_1",4,TP);
   add_action("step_2","alias");
   add_action("step_3","nickname");
   add_action("step_4","say");
   add_action("step_5","wimpy");
   add_action("step_6","wimpydir");
   add_action("step_7","party");
   add_action("step_8","nod");
   add_action("side_fun","ask");
}

void step_1(object target)
{
    if(!objectp(target)) return 0;
    if(!objectp(TO)) return 0;
    if(!present(target,ETO)) return 0;
    if(target->query("newbtutorial5") > 1)
    {
        tell_object(target,"\n\n%^RESET%^%^MAGENTA%^The short lean human turns to you "+
        "and says:%^RESET%^ Hello there.  Do you want to start again at where we left off?  If you can't remember "+
        "where you were up to, just %^YELLOW%^<ask>%^RESET%^ me.\n\nHe smiles broadly at you.");
        return;
    }
    else
    {
        tell_object(target,"\n\n%^RESET%^%^MAGENTA%^The short lean human smiles kindly at you and says:%^RESET%^ Hello "+
        "there.  I have some basics to teach you about the world that are really more of a convenience. First off, I want you to "+
        "types <%^YELLOW%^alias%^RESET%^>. This will show you a list of pre-defined aliases that have already been set up for you. "+
        "An alias works by allowing you to substitute one word for another.");
        target->set("newbtutorial5",1);
        return;
    }
}

int step_2(string str)
{
    if(((int)TP->query("newbtutorial5") != 1 && !str) ||
    ((int)TP->query("newbtutorial5") != 2 && stringp(str)))
    {
        return 0;
    }
    if(!stringp(str))
    {
        TP->set("newbtutorial5",2);
        TP->force_me("alias");
        tell_object(TP, "\n\n%^RESET%^%^MAGENTA%^The man speaks calmly: %^RESET%^you may have to hit the enter key on "+
        "your keyboard with a blank line in order to get through the list of aliases that the game has defined for you. "+
        "\n\nYou may notice the i alias defined as inventory in that list. This means that anytime you type the letter i "+
        "and send it to the game, the game substitutes i for inventory.\n\nThe help file for the command %^YELLOW%^<help "+
        "alias>%^RESET%^ is very useful. \n\n%^RESET%^%^MAGENTA%^The man speaks clearly and calmly:%^RESET%^ "+
        "Now, I want you to try to make an alias. When you are ready, I want you to type %^YELLOW%^<alias bc bury corpse>%^RESET%^\n\n"+
        "He watches you patiently.");
        return 1;
    }
    else if(stringp(str))
    {
        if(str != "bc bury corpse")
        {
            tell_object(TP, "\n%^RESET%^%^MAGENTA%^The man shakes his head before speaking:%^RESET%^ No, no, that's not quite "+
            "it. Just type %^YELLOW%^<alias bc bury corpse>%^RESET%^ when you are ready to continue.\n\nHe smiles warmly at you.");
            return 1;
        }
        TP->set("newbtutorial5",3);
        TP->force_me("alias bc bury corpse");
        tell_object(TP, "\n\n%^RESET%^%^MAGENTA%^The man cheers before speaking again:%^RESET%^ That's it. Now you have learned "+
        "how to establish your own aliases! They will become very useful as you explore the world. The particular alias that you "+
        "established will allow for you to type bc in order to bury a corpse that is in the room with you. This is a "+
        "very useful ability that is only available to you while you remain a newbie character. Burying a corpse will "+
        "allow for you to replenish some of your health.\n\n%^RESET%^%^MAGENTA%^His eyes flash before he speaks again:%^RESET%^ "+
        "Now, there is another command that is particularly useful "+
        "when you encounter something with a difficult-to-spell name. This command is called nickname. To continue, "+
        "simply type %^YELLOW%^<nickname>%^RESET%^.\n\nHe watches you patiently.");
        return 1;
    }
}

int step_3(string str)
{
    string myName;
    if(((int)TP->query("newbtutorial5") != 3 && !str) ||
    ((int)TP->query("newbtutorial5") != 4 && stringp(str)))
    {
        return 0;
    }
    myName = TPQN;
    if(!stringp(str))
    {
        TP->set("newbtutorial5",4);
        TP->force_me("nickname");
        tell_object(TP, "\n\n%^RESET%^%^MAGENTA%^The man speaks calmly: %^RESET%^Very good! Nicknames work almost like an alias "+
        "except their functionality is somewhat different. For example, if you type <nickname b "+
        "this is a test>, whenever you type the letter b anywhere, the game will substitute it for 'this is a test'. "+
        "Now, I want you to make a nickname. I want you to type %^YELLOW%^<nickname mynickname "+myName+">%^RESET%^. "+
        "This will cause the game to substitute your name, "+myName+", anytime you type the letters me.");
        return 1;
    }
    else if(stringp(str))
    {

        if(str != "mynickname "+ myName)
        {
            tell_object(TP, "\n%^RESET%^%^MAGENTA%^The man shakes his head before speaking:%^RESET%^ No, no, that's not quite "+
            "it. Just type %^YELLOW%^%^YELLOW%^<nickname mynickname "+myName+">%^RESET%^ when you are ready "+
            "to continue.\n\nHe smiles warmly at you.");
            return 1;
        }
        TP->set("newbtutorial5",5);
        TP->force_me("nickname mynickname "+myName);
        tell_object(TP, "\n\n%^RESET%^%^MAGENTA%^The man cheers before speaking again:%^RESET%^ That's it. Now you have learned "+
        "how to establish a nickname of your own! Nicknames are powerful and convenient when used properly. "
        "I want to show you an example of their functionality now. When you are ready I want you to "+
        "simply %^YELLOW%^<say mynickname is going to see the world!>%^RESET%^");
        return 1;
    }
}

int step_4(string str)
{
    string myName;
    int flag;
    if((int)TP->query("newbtutorial5") != 5) return 0;
    myName = TPQN;

    if(!str) flag = 1;
    else if(stringp(str))
    {
        if(strsrch(str, myName +" is going to see the world") == -1) flag = 1;
    }
    if(flag)
    {
        tell_object(TP,"\n%^RESET%^%^MAGENTA%^The man shakes his head before speaking:%^RESET%^ No, not that's not quite "+
        "it. Just type %^YELLOW%^<say mynickname is going to see the world!>%^RESET%^ when you are "+
        "ready to continue. I want you to see the functionality of nicknames in action!%^RESET%^");
        return 1;
    }
    TP->set("newbtutorial5",6);
    TP->force_me("say "+str);
    tell_object(TP, "\n\n%^RESET%^%^MAGENTA%^The man cheers loudly before speaking again:%^RESET%^ That is very good! "+
    "And yes you will! This is a perfect example of the functional power of nicknames. Remember them and use them "+
    "wisely as you explore the world of Sundering Shadows and make a name for yourself. See <help nickname> for how to "
    "adjust your nicknames and even delete them.\n\n%^RESET%^%^MAGENTA%^The man "+
    "continues speaking, quieter now and more serious:%^RESET%^ The world of Sundering Shadows is very large, and "+
    "there are many things that would see you dead. Sometimes they will succeed. You must not lose heart, though, "+
    "for death on Sundering Shadows is only temporary. Use the knowledge that you have learned here and "+
    "live a long prosperous life!\n\n%^RESET%^%^MAGENTA%^The man smiles once more before speaking again:%^RESET%^ "+
    "With that, I have nothing more to teach you. Your destiny awaits! Don't "+
    "forget you can remove the nickname you made by typing "+
    "%^BOLD%^%^YELLOW%^<unnickname mynickname>%^RESET%^");

   return 1;
}

int side_fun(string str)
{
    int tracker;
    string myName;
    tracker = (int)TP->query("newbtutorial5");
    if(!tracker) {
        call_out("step_1",2,TP);
        return 1;
    }
    myName = TPQN;
    tell_object(TP,"%^RESET%^%^MAGENTA%^The man speaks quietly:%^RESET%^ Have you forgotten where you were up to? "
    " Ok, let's try again.");
    switch(tracker)
    {
        case 1:
            tell_object(TP,"%^RESET%^%^MAGENTA%^He says:%^RESET%^ simply type %^YELLOW%^<alias>"
            "%^RESET%^ when you are ready to continue.");
            break;
        case 2:
            tell_object(TP,"%^RESET%^%^MAGENTA%^He says:%^RESET%^ try establishing an alias of "+
            "your own. Type %^YELLOW%^<alias bc bury corpse>%^RESET%^ when you are ready to continue.");
            break;
        case 3:
            tell_object(TP,"%^RESET%^%^MAGENTA%^He says:%^RESET%^ simply type %^YELLOW%^<nickname>"+
            "%^RESET%^ when you are ready to continue.");
            break;
        case 4:
            tell_object(TP,"%^RESET%^%^MAGENTA%^He says:%^RESET%^ try establishing a nickname of "+
            "your own. Simply type %^YELLOW%^<nickname mynickname "+myName+">%^RESET%^ when "+
            "you are ready to continue.%^RESET%^");
            break;
        case 5:
            tell_object(TP,"%^RESET%^%^MAGENTA%^He says:%^RESET%^ to understand how the functionality of "+
            "a nickname I want you to simply %^YELLOW%^<say mynickname is going to see the world!>%^RESET%^ "+
            "when you are ready to continue.");
            break;
        case 6:
            tell_object(TP,"%^RESET%^%^MAGENTA%^He says:%^RESET%^ I have taught you all that I can. "+
            "Your destiny awaits! Don't forget you can remove the nickname you made by typing "+
            "%^BOLD%^%^YELLOW%^<unnickname mynickname>");
            break;
   }
   return 1;
}
