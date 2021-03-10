#include <std.h>
#include "../inherits/area_stuff.h"
#define ALPHA ({"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"})

inherit "/std/bag_logic";
string puzzle;
string solution, *current, *mychoices;
int solved;

void set_up_current()
{
    int x;
    string this, *NUMS, *poss_cols, *picture_choices;
    NUMS = ({"1", "2", "3", "4", "5", "6", "7", "8", "9"});    
    poss_cols = ({"%^RED%^", "%^GREEN%^", "%^CYAN%^", "%^MAGENTA%^", "%^ORANGE%^", "%^WHITE%^"});  
    picture_choices = ({"skeleton", "zombie", "ghoul", "ghost", "werewolf", "goblin", "hobgoblin", "gnoll"});    
    switch(puzzle)
    {
        case "word puzzle":
            current = allocate(8);
            for(x = 0;x < sizeof(current);x++)
            {
                current[x] = capitalize(ALPHA[random(sizeof(ALPHA))]);
                continue;
            }
            break;
        case "number puzzle":
            current = allocate(9);
            for(x = 0;x < sizeof(current);x++)
            {                
                this = NUMS[random(sizeof(NUMS))];
                NUMS -= ({this});
                current[x] = this;
                continue;
            }            
            break;
        case "sphere puzzle":
            current = allocate(6);
            for(x = 0;x < sizeof(current);x++)
            {
                this = poss_cols[random(sizeof(poss_cols))];
                poss_cols -= ({this});
                current[x] = "%^BOLD%^%^BLACK%^(%^RESET%^"+this+"*%^BOLD%^%^BLACK%^)";
                continue;
            }
            break;
        case "picture puzzle":
            current = allocate(8);
            for(x = 0;x < sizeof(current);x++)
            {
                this = picture_choices[random(sizeof(picture_choices))];
                picture_choices -= ({this});
                current[x] = this;
                continue;
            }
            break;
    }
    return;
}
void set_my_solution(string str) { solution = str; }
string get_my_solution() { return solution; }
void set_my_puzzle(string str) { puzzle = str; mychoices = ({}); set_up_current(); solved = 0; }
mixed get_my_current() { return identify(current); }

string get_my_long()
{
    string ret;
    ret = "%^RESET%^%^ORANGE%^This sarcophagus is nearly twenty "+
    "feet long. It rises almost two feet from the floor. It was obviously "+
    "intended to be the centerpiece of this tomb. It is made from a flawless "+
    "%^BOLD%^%^BLACK%^dark m%^BOLD%^%^WHITE%^a%^BOLD%^%^BLACK%^rble%^RESET%^"+
    "%^ORANGE%^ that has ornate %^BOLD%^%^CYAN%^runes%^RESET%^%^ORANGE%^ "+
    "covering almost the entire surface of it.";
    if(solved)
    {
        ret +=  " The entire top of the sarcophagus has been split open by "+
        "something.%^RESET%^";
    }
    else 
    {
        ret +=  " There appears to be no visible "+
        "means to opening it, there is no lid, in fact it is one solid "+
        "piece of %^BOLD%^%^BLACK%^dark m%^BOLD%^%^WHITE%^a%^BOLD%^%^BLACK%^"+
        "rble%^RESET%^%^ORANGE%^.%^RESET%^";
        if(stringp(puzzle))
        {
            if(!pointerp(current)) set_up_current();
            switch(puzzle)
            {
                case "word puzzle":
                    ret += "%^RESET%^%^ORANGE%^ There are %^BOLD%^%^CYAN%^"+
                    "eight letters%^RESET%^%^ORANGE%^ in a flowing script engraved into the top of it. \n\n"+
                    "%^BOLD%^%^CYAN%^\t"+implode(current, " ")+"\n\n"+
                    "%^RESET%^%^ORANGE%^You get the urge to <%^BOLD%^%^CYAN%^change letter 1-8 to letter%^RESET%^%^ORANGE%^> "+
                    "... and you realize that this would change the specified letter to whatever letter you want. "+
                    "Perhaps the letters are the key to opening this sarcophagus.%^RESET%^";
                    break;
                case "number puzzle":
                    ret += "%^RESET%^%^ORANGE%^ There is a grid of %^BOLD%^%^YELLOW%^numbers%^RESET%^%^ORANGE%^ "+
                    "engraved into the top of it. An arrow points northward just above the grid.\n\n"+
                    "%^BOLD%^%^CYAN%^\t"+implode(current[0..2], " ")+"\n"+
                    "%^BOLD%^%^CYAN%^\t"+implode(current[3..5], " ")+"\n"+
                    "%^BOLD%^%^CYAN%^\t"+implode(current[6..8], " ")+"\n\n"+
                    "%^RESET%^%^ORANGE%^You feel that you could <%^BOLD%^%^CYAN%^slide number direction%^RESET%^%^ORANGE%^> "+
                    "to change the location of a particular number in the grid.... perhaps the numbers are the "+
                    "key to opening this sarcophagus.%^RESET%^";
                    break;  
                case "sphere puzzle":
                    ret += "%^RESET%^%^ORANGE%^ There are six small %^BOLD%^%^WHITE%^spheres%^RESET%^%^ORANGE%^ "+
                    "of various colors inset into the top of the sarcophagus.\n\n"+
                    "%^BOLD%^%^CYAN%^\t"+implode(current, " ")+"\n\n"+
                    "%^RESET%^%^ORANGE%^You get the urge to <%^BOLD%^%^CYAN%^touch color sphere%^RESET%^%^ORANGE%^> "+
                    "...perhaps the order in which the spheres are touched is the key to opening this "+
                    "sarcophagus.%^RESET%^";
                    break;
                case "picture puzzle":
                    ret += "%^RESET%^%^ORANGE%^ There are small %^BOLD%^%^CYAN%^drawings%^RESET%^%^ORANGE%^ "+
                    "of the following creatures on top of the sarcophagus.\n\n"+
                    "%^RESET%^%^GREEN%^a "+implode(current[0..6], ", ")+" and a "+current[7]+".\n\n"+
                    "%^RESET%^%^ORANGE%^You get the urge to <%^BOLD%^%^CYAN%^touch drawing of creature>%^RESET%^%^ORANGE%^ "+
                    "...perhaps the order in which the drawings are touched is the key to opening this "+
                    "sarcophagus.%^RESET%^";
                    break;
            }
                
        }
    }
    return ret;
}

void create() 
{
    ::create();
    set_no_clean(1);
    set_closed(1);
    set_possible_to_close(0);	
    solved = 0;
    set_short("%^RESET%^%^ORANGE%^A large ornate sarcophagus%^RESET%^");    
    set_long((:TO, "get_my_long":));
    
    set_id(({"sarcophagus"}));
    set_weight(10000);
    set_property("no animate", 1);
    set_name("large sarcophagus");
}

void init()
{
    ::init();
    add_action("touch", "touch");
    add_action("slide", "slide");
    add_action("change", "change");
}

void assign_treasure()
{
    string *TREASURE_FILES = ({"/d/deku/armours/ring", "/d/deku/armours/cloak1",
    "/d/deku/armours/plate", "/d/deku/armours/bracers", "/d/deku/misc/hstone",
    "/d/deku/weapons/elf_slayer", "/d/deku/weapons/dagger2", "/d/deku/weapons/whip2",
    "/d/common/obj/brewing/oils/fire_oil", "/d/common/obj/brewing/frost_oil",
    "/d/common/obj/brewing/oils/oil_of_curse_removal", 
    "/d/common/obj/brewing/oils/wizard_oil"});
    
    string *OILS = ({"/d/common/obj/brewing/oils/fire_oil", "/d/common/obj/brewing/frost_oil",
    "/d/common/obj/brewing/oils/oil_of_curse_removal", 
    "/d/common/obj/brewing/oils/wizard_oil"});
    string file;
    
    object ob;
    int amt;
    amt = 2 + random(3);
    if(!objectp(TO)) return;
    if(!solved) return;
    while(amt--)
    {
        switch(random(101))
        {
            case 0..25: case 28..44: case 46..75: case 78..95: case 98..100:
                ob = new("/std/obj/coins");
                ob->add_money("gold",1200 + random(1500));
                ob->move(TO);
                break;
            case 27: case 45: case 76: case 97:
                ob = new("/d/magic/scroll");
                ob->set_spell(3 + random(7));
                ob->move(TO);
                break;
            case 26: case 77: case 96:
                file = TREASURE_FILES[random(sizeof(TREASURE_FILES))];
                TREASURE_FILES -= ({file});
                if(member_array(file, OILS) != -1) TREASURE_FILES -= OILS;
                ob = new(file);
                ob->move(TO);
                break;
        }
    }
    return;
}

int check_solution()
{
    object ob;
    if(!pointerp(mychoices)) return 0;
    //if(!stringp(solution)) return 0;
    if(implode(mychoices, "") == solution)
    {
        tell_room(ETO, "%^RESET%^%^ORANGE%^With a vicious hiss.... the sarcophagus "+
        "splits open!%^RESET%^");
        solved = 1;
        all_inventory(TO)->remove();
        ob = new(MOBJ"lever");
        ob->set_lever_type(puzzle);
        ob->move(TO);
        assign_treasure();
        return 1;
    }
    if(puzzle == "number puzzle" && sizeof(mychoices) > 8)
    {
        mychoices = ({});
    }
    else if(sizeof(mychoices) > 7 && puzzle != "number puzzle") 
    {
        mychoices = ({});
        if(puzzle == "sphere puzzle" || puzzle == "picture puzzle")
        {
            tell_room(ETO, "%^RESET%^%^ORANGE%^A deep groaning echoes from within the "+
            "sarcophagus for a brief moment before it goes silent.%^RESET%^");
        }        
    }
    return 0;
}

string *fix_current()
{
    int x;
    if(!pointerp(current)) return ({});
    mychoices = allocate(sizeof(current));
    for(x = 0;x < sizeof(current);x++)
    {
        mychoices[x] = lower_case(current[x]);
        continue;
    }
    return mychoices;
}

string *build_valid_directions(int loc)
{
    if(!intp(loc)) return ({});
    if(loc < 0) return ({});
    if(loc > 8) return ({});
    if(loc == 0) return ({"right", "down"});
    if(loc == 1) return ({"left", "right", "down"});
    if(loc == 2) return ({"left", "down"});
    if(loc == 3) return ({"right", "up", "down"});
    if(loc == 4) return ({"left", "right", "up", "down"});
    if(loc == 5) return ({"left", "up", "down"});
    if(loc == 6) return ({"up", "right"});
    if(loc == 7) return ({"right", "up", "left"});
    if(loc == 8) return ({"up", "left"});
    return ({});
}

int get_target_location(int loc, string dir)
{
    if(!intp(loc)) return -1;
    if(!stringp(dir)) return -1;
    switch(loc)
    {
        case 0:
            if(dir == "right") return 1;
            else if(dir == "down") return 3;
            else return -1;
        case 1:
            if(dir == "right") return 2;
            else if(dir == "down") return 4;
            else if(dir == "left") return 0;
            else return -1;
        case 2:
            if(dir == "left") return 1;
            else if(dir == "down") return 5;
            else return -1;
        case 3:
            if(dir == "up") return 0;
            else if(dir == "down") return 6;
            else if(dir == "right") return 4;
            else return -1;
        case 4:
            if(dir == "up") return 1;
            else if(dir == "down") return 7;
            else if(dir == "left") return 3;
            else if(dir == "right") return 5;
            else return -1;
        case 5:
            if(dir == "up") return 2;
            else if(dir == "down") return 8;
            else if(dir == "left") return 4;
            else return -1;
        case 6:
            if(dir == "up") return 3;
            else if(dir == "right") return 7;
            else return -1;
        case 7:
            if(dir == "left") return 6;
            else if(dir == "up") return 4;
            else if(dir == "right") return 8;
            else return -1;
        case 8:
            if(dir == "up") return 5;
            else if(dir == "left") return 7;
            else return -1;
    }
    return -1;
}

int slide(string str)
{
    string num, dir, *vdirs, tar_num;
    int loc, tar;
    if(!objectp(TO)) return 0;
    if(solved) return 0;
    if(!objectp(ETO)) return 0;
    if(!objectp(TP)) return 0;
    if(!stringp(str)) return 0;
    if(!stringp(puzzle)) return 0;
    if(!sizeof(current)) set_up_current();
    if(puzzle != "number puzzle") return 0;
    if(sscanf(str, "%s %s", num, dir) != 2)
    {
        tell_object(TP, "%^BOLD%^%^WHITE%^Try <slide number direction>%^RESET%^");
        return 1;
    }
    loc = member_array(num, current);
    if(loc == -1)
    {
        tell_object(TP, "%^BOLD%^%^WHITE%^Try a real number.%^RESET%^");
        return 1;
    }
    vdirs = build_valid_directions(loc);
    if(member_array(dir, vdirs) == -1)
    {
        tell_object(TP, "%^BOLD%^%^WHITE%^You cannot slide "+num+" in that direction.%^RESET%^");
        return 1;
    }
    tar = get_target_location(loc, dir);
    if(tar == -1)
    {
        tell_object(TP, "Something went wrong...");
        return 1;
    }
    tell_object(TP, "%^BOLD%^%^WHITE%^You slide the "+num+" in the grid on top of the sarcophagus "+
    dir+".%^RESET%^");
    tell_room(ETO, TPQCN+"%^BOLD%^%^WHITE%^ slides the "+num+" in the grid on top of the "+
    "sarcophagus "+dir+".%^RESET%^", TP);
    tar_num = current[tar];
    current[tar] = num;
    current[loc] = tar_num;
    mychoices = current;
    check_solution();
    return 1;    
}

int change(string str)
{
    string let, tar, cur_let;
    int num;
    if(!objectp(TO)) return 0;
    if(solved) return 0;
    if(!objectp(ETO)) return 0;
    if(!objectp(TP)) return 0;
    if(!stringp(str)) return 0;
    if(!stringp(puzzle)) return 0;
    if(!sizeof(current)) set_up_current();
    if(puzzle != "word puzzle") return 0;
    if(sscanf(str, "letter %s to %s", tar, let) != 2)
    {
        tell_object(TP, "%^BOLD%^%^WHITE%^Try <change letter 1 to a>%^RESET%^");
        return 1;
    }
    tar = lower_case(tar);
    let = lower_case(let);
    if(member_array(let, ALPHA) == -1)
    {
        tell_object(TP, "%^BOLD%^%^WHITE%^Try a normal letter.%^RESET%^");
        return 1;
    }
    num = to_int(tar);
    if(num < 1 || num > 8) 
    {
        tell_object(TP, "%^BOLD%^%^WHITE%^Try changing a letter 1 through 8.%^RESET%^");
        return 1;
    }
    num--;    
    cur_let = lower_case(current[num]);
    if(!pointerp(mychoices) || !sizeof(mychoices)) mychoices = fix_current();
    if(let == cur_let)
    {
        tell_object(TP, "%^BOLD%^%^WHITE%^That letter is already a "+capitalize(cur_let)+". Try something else.");
        return 1;
    }
    mychoices[num] = let;
    current[num] = capitalize(let);
    tell_object(TP, "%^BOLD%^%^WHITE%^You change letter "+tar+" on top of the sarcophagus from "+
    "a "+capitalize(cur_let)+" to a "+capitalize(let)+".%^RESET%^");    
    tell_room(ETO, TPQCN+"%^BOLD%^%^WHITE%^ changes letter "+tar+" on top of the sarcophagus from "+
    "a "+capitalize(cur_let)+" to a "+capitalize(let)+".%^RESET%^", TP);
    check_solution();
    return 1;   
}

int touch(string str)
{
    string tar, *spheres, *drawings;    
    spheres = ({"red", "green", "cyan", "pink", "orange", "white"});
    drawings = ({"skeleton", "zombie", "ghoul", "ghost", "werewolf", "goblin", "hobgoblin", "gnoll"});   
    if(!objectp(TO)) return 0;
    if(solved) return 0;
    if(!objectp(ETO)) return 0;
    if(!objectp(TP)) return 0;
    if(!stringp(str)) return 0; 
    if(!stringp(puzzle)) return 0;
    if(!sizeof(current)) set_up_current();
    if(puzzle != "sphere puzzle" && puzzle != "picture puzzle") return 0;
    if(!pointerp(mychoices)) mychoices = ({});
    if(check_solution()) return 1;
    switch(puzzle)
    {
        case "sphere puzzle":
            if(sscanf(str, "%s sphere", tar) != 1)
            {
                tell_object(TP, "%^BOLD%^%^WHITE%^Try <touch blue sphere>%^RESET%^");
                return 1;
            }
            if(tar == "blue") tar = "cyan";
            if(tar == "magenta") tar = "pink";
            if(tar == "yellow") tar = "orange";
            if(member_array(tar, spheres) == -1)
            {
                tell_object(TP, "%^BOLD%^%^WHITE%^There is a "+implode(spheres[0..4], ", ")+ " and " +
                spheres[5]+" that you can touch.%^RESET%^");
                return 1;
            }
            mychoices += ({tar});
            tell_object(TP, "%^BOLD%^%^WHITE%^You touch the "+tar+" sphere inset "+
            "into the top of the sarcophagus.%^RESET%^");
            tell_room(ETO, TPQCN+"%^BOLD%^%^WHITE%^ touches the "+tar+" sphere inset "+
            "into the top of the sarcophagus.%^RESET%^", TP);
            if(check_solution()) return 1;
            return 1;
            break;
        case "picture puzzle":
            if(sscanf(str, "drawing of %s", tar) != 1)
            {
                tell_object(TP, "%^BOLD%^%^WHITE%^Try <touch drawing of werewolf>%^RESET%^");
                return 1;
            }
            if(member_array(tar, drawings) == -1)
            {
                tell_object(TP, "%^BOLD%^%^WHITE%^There are drawings of a "+implode(drawings[0..6], ", ") + 
                " and a "+drawings[7]+" that you can touch.%^RESET%^");
                return 1;
            }
            mychoices += ({tar});
            tell_object(TP, "%^BOLD%^%^WHITE%^You touch the drawing of the "+tar+ 
            " on top of the sarcophagus.%^RESET%^");
            tell_room(ETO, TPQCN+"%^BOLD%^%^WHITE%^ touches the drawing of the "+tar+
            " on top of the sarcophagus.%^RESET%^", TP);            
            if(check_solution()) return 1;
            return 1;
            break;
    }
}

int put_into(string str) { return 0; }
int open_container(string str) { return 0;}