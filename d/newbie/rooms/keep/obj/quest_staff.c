#include <std.h>
#include "../../inherit/keep.h"
inherit OBJECT;
string mypart;

void create() 
{
    ::create();
    set_short("You should not see this!");
}
void set_mypart(string str) { mypart = str; }

void init() 
{
   ::init();
   add_action("assemble_fun","assemble");
}

int assemble_fun(string str) 
{
    object obj1, obj2, obj3, obj4;
    string ms = "\n%^BOLD%^%^WHITE%^You are missing : \n%^RESET%^";
    if(TP != ETO) return 0;
    if(!objectp(ETO)) return 0;
    if(str) return notify_fail("Just <assemble> it.\n");  
    
    obj1 = present("staff-part-1", ETO);
    obj2 = present("staff-part-2", ETO);
    obj3 = present("staff-part-3", ETO);
    obj4 = present("staff-part-4", ETO);
    
    if((!objectp(obj1) || obj1 == TO) && 
    (!objectp(obj2) || obj2 == TO) && 
    (!objectp(obj3) || obj3 == TO) && 
    (!objectp(obj4) || obj4 == TO))
    {
        tell_object(ETO, "%^YELLOW%^You examine the "+mypart+", but realise you have "
        "no other parts to assemble it with.%^RESET%^");        
        if(!objectp(obj1)) ms += "%^BOLD%^%^CYAN%^an orb for the top of staff%^RESET%^\n";
        if(!objectp(obj2)) ms += "%^RESET%^%^RED%^a carved dragon to hold the orb%^RESET%^\n"; 
        if(!objectp(obj3)) ms += "%^RESET%^%^ORANGE%^a runed staff to hold it all together%^RESET%^\n";
        if(!objectp(obj4)) ms += "%^YELLOW%^golden bands to bind it all%^RESET%^\n";
        tell_object(ETO, ms);
        return 1;
    }
    //tell_object(ETO, identify(obj1) + " " + identify(obj2)+" " +identify(obj3)+ " " + identify(obj4));
    if(!objectp(obj1) || !objectp(obj2) || !objectp(obj3) || !objectp(obj4)) 
    {
        tell_object(ETO,"%^YELLOW%^You examine the "+mypart+", but realise you do "
        "not have enough other parts to assemble it with.%^RESET%^");
        if(!objectp(obj1)) ms += "%^BOLD%^%^CYAN%^an orb for the top of staff%^RESET%^\n";
        if(!objectp(obj2)) ms += "%^RESET%^%^RED%^a carved dragon to hold the orb%^RESET%^\n"; 
        if(!objectp(obj3)) ms += "%^RESET%^%^ORANGE%^a runed staff to hold it all together%^RESET%^\n";
        if(!objectp(obj4)) ms += "%^YELLOW%^golden bands to bind it all%^RESET%^\n";
        tell_object(ETO, ms);
        return 1;
    }
    if(base_name(obj1) != OBJ2"stafforb")
    {
        tell_object(TP, "%^YELLOW%^The orb does not seem to fit correctly "+
        "with the other pieces.%^RESET%^");
        return 1;
    }
    if(base_name(obj2) != OBJ2"staffdragon") 
    {
        tell_object(TP,"%^YELLOW%^The dragon carving does not seem to fit "
        "correctly with the other pieces.%^RESET%^");
        return 1;
    }
    if(base_name(obj3) != OBJ2"staffstave") 
    {
        tell_object(TP,"%^YELLOW%^The runed stave does not seem to fit "
        "correctly with the other pieces.%^RESET%^");
        return 1;
    }
    if(base_name(obj4) != OBJ2"staffbands") 
    {
        tell_object(TP,"%^YELLOW%^The golden bands do not seem to fit "
        "correctly with the other pieces.%^RESET%^");
        return 1;
    }
    tell_object(TP,"%^BOLD%^%^WHITE%^You pause for a moment, connecting all "
    "the pieces together.  The %^RESET%^%^CYAN%^orb%^BOLD%^%^WHITE%^ sits "
    "perfectly within the grasp of the %^RESET%^%^RED%^carved dragon%^BOLD%^"
    "%^WHITE%^, which sockets perfectly atop the %^RESET%^%^ORANGE%^runed stave"
    "%^BOLD%^%^WHITE%^.  The two %^YELLOW%^golden bands %^WHITE%^bind the other "
    "indentations along its length, leaving you with an impressive looking "
    "staff.%^RESET%^");
    if(obj1 != TO && objectp(obj1)) obj1->remove();
    if(obj2 != TO && objectp(obj2)) obj2->remove();
    if(obj3 != TO && objectp(obj3)) obj3->remove();
    if(obj4 != TO && objectp(obj4)) obj4->remove();
    new(OBJ2"staff")->move(TP);
    TO->remove();
    return 1;
}
