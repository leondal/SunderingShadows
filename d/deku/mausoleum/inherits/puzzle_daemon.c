/*=========================================
A puzzle daemon - assigns a puzzle type to 
tomb rooms when the assign_puzzles function is 
called. This determine the particular description of the tomb
IE provides hint to the puzzle solution
varies - so puzzles should remain the same for 
a window of 2 hours - will not change on reset
but will change when the room is reloaded 
=========================================*/

#include <std.h>
#include "area_stuff.h"
#include "drawings.h"
inherit DAEMON;

//mapping PUZZLES (["word puzzle" : (["current solution": "", "current tomb" : 1-4, "room" : "hint"]), ])
mapping PUZZLES = ([]);
int PUZZLE_DELAY;
mapping DOPPLEGANGERS = ([]);

void assign_puzzles();
void install_puzzles(object room);
void actual_puzzle_assignment();
void assign_word_puzzle();
void assign_number_puzzle();
void assign_picture_puzzle();
void assign_sphere_puzzle();
mapping query_puzzles() { return PUZZLES; }
string assign_random_letters(int hint);
string get_puzzle_solution(string type);
mixed is_puzzle_room(string myRoom, string type);
string *get_puzzle_rooms(int tomb);
string assign_random_colors(string hint, string myRoom);
mapping default_items();
mixed get_sarcophagus_type(string myRoom);

void assign_puzzles()
{
    string *saved_arr;
    int delay;
    if(!PUZZLE_DELAY || !mapp(PUZZLES))
    {
        PUZZLE_DELAY = time() + 7200;   
        PUZZLES = ([]);
        actual_puzzle_assignment();
        return;
    }
    else
    {
        if(time() > PUZZLE_DELAY || !mapp(PUZZLES))
        {
            PUZZLES = ([]);
            PUZZLE_DELAY = time() + 7200;  
            actual_puzzle_assignment();
            return;
        }
        else return;
    }   
}

void actual_puzzle_assignment()
{
    string *puzzles = ({"word puzzle", "number puzzle", "sphere puzzle", "picture puzzle"});
    string cur_puzzle;
    int *nums = ({1, 2, 3, 4});
    int cur_tomb;
    while(sizeof(nums))
    {
        cur_puzzle = puzzles[random(sizeof(puzzles))];
        puzzles -= ({cur_puzzle});
        cur_tomb = nums[random(sizeof(nums))];
        nums -= ({cur_tomb});
        PUZZLES += ([cur_puzzle : (["current solution" : "", "sarcophagus location" : MAUS+"tomb"+cur_tomb+"_5.c", "current tomb" : cur_tomb, "rooms" : ([]), ]), ]);
        continue;
    }
    assign_word_puzzle();
    assign_sphere_puzzle();
    assign_picture_puzzle();
    assign_number_puzzle();    
}

mixed get_sarcophagus_type(string myRoom)
{
    if(!stringp(myRoom)) return 0;
    if(!mapp(PUZZLES) || !sizeof(keys(PUZZLES))) assign_puzzles();
    if(PUZZLES["word puzzle"]["sarcophagus location"] == myRoom) return "word puzzle";
    else if(PUZZLES["number puzzle"]["sarcophagus location"] == myRoom) return "number puzzle";
    else if(PUZZLES["sphere puzzle"]["sarcophagus location"] == myRoom) return "sphere puzzle";
    else if(PUZZLES["picture puzzle"]["sarcophagus location"] == myRoom) return "picture puzzle";
    return 0;
}

mixed is_puzzle_room(string myRoom, string type)
{
    string *myRooms;
    if(!stringp(myRoom)) return 0;
    if(!mapp(PUZZLES) || !sizeof(keys(PUZZLES))) assign_puzzles();
    if(!mapp(PUZZLES[type]["rooms"])) return 0;
    myRooms = keys(PUZZLES[type]["rooms"]);
    if(!pointerp(myRooms)) return 0;
    if(member_array(myRoom, myRooms) == -1) return 0;
    if(type == "sphere puzzle" || type == "picture puzzle")
    {
        return PUZZLES[type]["rooms"][myRoom]["hint"];
    }
    return PUZZLES[type]["rooms"][myRoom];
}

string *get_puzzle_rooms(int tomb)
{
    string *rooms, mydir;
    mydir = MAUS+"tomb"+tomb+"_*.c";
    rooms = get_dir(mydir);
    rooms -= ({"tomb"+tomb+"_5.c"});
    return rooms;
}

string get_puzzle_solution(string type)
{
    if(!mapp(PUZZLES)) assign_puzzles();    
    return PUZZLES[type]["current solution"];    
}

void assign_number_puzzle()
{
    string *NUMS = ({"1", "2", "3", "4", "5", "6", "7", "8", "9"});
    string *solution, num, *rooms;
    int tomb;
    solution = ({});
    while(sizeof(NUMS))
    {
        num = NUMS[random(sizeof(NUMS))];
        solution += ({num});
        NUMS -= ({num});
        continue;
    }
    tomb = PUZZLES["number puzzle"]["current tomb"];
    PUZZLES["number puzzle"]["current solution"] = implode(solution,"");
    PUZZLES["number puzzle"]["rooms"] += ([MAUS + "tomb"+tomb+"_1.c" : solution[0]]);
    PUZZLES["number puzzle"]["rooms"] += ([MAUS + "tomb"+tomb+"_2.c" : solution[1]]);
    PUZZLES["number puzzle"]["rooms"] += ([MAUS + "tomb"+tomb+"_3.c" : solution[2]]);
    PUZZLES["number puzzle"]["rooms"] += ([MAUS + "tomb"+tomb+"_4.c" : solution[3]]);
    PUZZLES["number puzzle"]["rooms"] += ([MAUS + "tomb"+tomb+"_6.c" : solution[5]]);
    PUZZLES["number puzzle"]["rooms"] += ([MAUS + "tomb"+tomb+"_7.c" : solution[6]]);
    PUZZLES["number puzzle"]["rooms"] += ([MAUS + "tomb"+tomb+"_8.c" : solution[7]]);
    PUZZLES["number puzzle"]["rooms"] += ([MAUS + "tomb"+tomb+"_9.c" : solution[8]]);
    return;
}

void assign_sphere_puzzle()
{
    string *poss_colors = ({"red", "green", "cyan", "pink", "orange", "white"});      
    string *solution, hint, *rooms, room;
    int tomb, order;
    tomb = PUZZLES["sphere puzzle"]["current tomb"];
    rooms = get_puzzle_rooms(tomb);
    solution = ({});
    order = 1;
    while(sizeof(rooms))
    {
        room = rooms[random(sizeof(rooms))];        
        hint = poss_colors[random(sizeof(poss_colors))];
        solution += ({hint});
        rooms -= ({room});
        room = MAUS + room;
        PUZZLES["sphere puzzle"]["rooms"] += ([room : ([ "hint" : hint, "order" : order ]), ]);
        order++;
        continue;
    }    
    PUZZLES["sphere puzzle"]["current solution"] = implode(solution, "");
    return;
    
}

void assign_picture_puzzle()
{
    string *picture_choices = ({"skeleton", "zombie", "ghoul", "ghost", "werewolf", "goblin", "hobgoblin", "gnoll"});
    string *solution, hint, *rooms, room;
    int tomb, order;
    tomb = PUZZLES["picture puzzle"]["current tomb"];
    rooms = get_puzzle_rooms(tomb);
    solution = ({});
    order = 1;
    while(sizeof(rooms))
    {
        room = rooms[random(sizeof(rooms))];
        hint = picture_choices[random(sizeof(picture_choices))];
        solution += ({hint});
        rooms -= ({room});
        room = MAUS + room;
        PUZZLES["picture puzzle"]["rooms"] += ([room : (["hint" : hint, "order" : order]), ]);
        order++;
        continue;
    }
    PUZZLES["picture puzzle"]["current solution"] = implode(solution, "");
    return;
}

void assign_word_puzzle()
{
    string *hints, *rooms, room, hint;
    string *WORD_CHOICES = ({"mountain","desolate","possible","conclude",
    "evolving","insanity","darkness","dramatic","solution","horrible",
    "unliving","unsteady","collapse","drowning","morphing","changing"});
    string myWord = WORD_CHOICES[random(sizeof(WORD_CHOICES))];
    int tomb, num, max;
    
    tomb = PUZZLES["word puzzle"]["current tomb"];
    hints = explode(myWord, "");
    PUZZLES["word puzzle"]["current solution"] = myWord;
    rooms = get_puzzle_rooms(tomb);
    if(!sizeof(rooms)) return;
  
    while(sizeof(hints))
    {
        room = rooms[random(sizeof(rooms))];
        rooms -= ({room});
        num = random(sizeof(hints));
        max = (sizeof(hints) - 1);
        hint = hints[num];
        if(max == 0) hints -= ({hint});
        else if(num == 0) hints = hints[1..max];
        else hints = hints[0..(num-1)] + hints[(num+1)..max];
        room = MAUS + room;
        PUZZLES["word puzzle"]["rooms"] += ([room : hint]);
        continue;
    }
    return;        
}

string assign_random_numbers(string hint)
{
    string *NUMS = ({"1", "2", "3", "4", "5", "6", "7", "8", "9"});
    string *num_hint, num;
    int x, flag;
    x = 3 + random(4);
    num_hint = ({});
    while(x > 0)
    {
        num = NUMS[random(sizeof(NUMS))];
        if(num == hint && !flag) { num = "%^BOLD%^%^CYAN%^("+num+")%^RESET%^"; flag = 1; }
        else num = "%^BOLD%^%^GREEN%^"+num+"%^RESET%^";
        num_hint += ({num});
        x--;
    }
    if(!flag)
    {
        num_hint[random(sizeof(num_hint))] = "%^BOLD%^%^CYAN%^("+hint+")%^RESET%^";
    }
    return implode(num_hint, " ");   
}

string assign_random_letters(string hint)
{
    string *LETS = ({"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"});
    string let;
    string *let_hint;
    int x, flag;
    
    x = 4 + random(7);
    let_hint = ({});
    while(x > 0)
    {
        let = LETS[random(sizeof(LETS))];        
        LETS -= ({let});
        if(let == hint && !flag) { let = "%^BOLD%^%^CYAN%^("+capitalize(let)+")%^RESET%^"; flag = 1; }
        else let = "%^BOLD%^%^GREEN%^"+capitalize(let)+"%^RESET%^";
        let_hint += ({let});
        x--;
    }
    if(!flag)
    {
        let_hint[random(sizeof(let_hint))] = "%^BOLD%^%^CYAN%^("+capitalize(hint)+")%^RESET%^";
    }
    return implode(let_hint, " ");
}

string assign_random_colors(string hint, string myRoom)
{
    mapping myColors = (["red" : "%^RED%^", "green" : "%^GREEN%^", "cyan" : "%^CYAN%^", "pink" : "%^MAGENTA%^", "orange" : "%^ORANGE%^", "white" : "%^WHITE%^"]);
    string *poss_colors = ({"red", "green", "cyan", "pink", "orange", "white"});
    string *let_hint, let;
    int order, x;
    let_hint = ({});
    order = PUZZLES["sphere puzzle"]["rooms"][myRoom]["order"];
    x = 1;
    while(x < 9)
    {    
        if(x == order) { let = "%^BOLD%^%^BLACK%^(%^RESET%^%^BOLD%^"+myColors[hint]+"*%^BOLD%^%^BLACK%^)%^RESET%^"; }        
        else
        {
            let = poss_colors[random(sizeof(poss_colors))];
            let = "%^BOLD%^%^BLACK%^(%^RESET%^"+myColors[let]+"o%^BOLD%^%^BLACK%^)%^RESET%^";
        }
        let_hint += ({let});
        x++;
        continue;
    }
    return implode(let_hint, " ");   
}

string assign_random_pictures(string hint, string myRoom)
{
    string *picture_choices = ({"skeleton", "zombie", "ghoul", "ghost", "werewolf", "goblin", "hobgoblin", "gnoll"});
    string *let_hint, let, pic;
    int order, x;
    let_hint = ({});
    order = PUZZLES["picture puzzle"]["rooms"][myRoom]["order"];
    x = 1;
    picture_choices -= ({hint});
    while(x < 9)
    {
        if(x == order) { let = hint; }
        else 
        {            
            let = picture_choices[random(sizeof(picture_choices))];
            picture_choices -= ({let});
        }
        let_hint += ({let});
        x++;
        continue;
    }
    return "a " +implode(let_hint[0..6], ", ") + " and a "+let_hint[7];
}

mapping default_items()
{
    mapping tmp; 
    tmp = ([({"tomb", "structure", "mausoleum", "stone"}) : "%^BOLD%^%^WHITE%^This ancient "+
    "tomb, like the rest of the mausoleum, was obviously once quite grand. However, "+
    "that time has long since passed. It looks as if no one has visited it in ages and "+
    "obviously whoever or whatever may have once cared for it has ceased.%^RESET%^",   
    ({"torch holders", "holders", "dust", "cobwebs"}) : "%^BOLD%^%^YELLOW%^These are all empty now and "+
    "covered with dust and cobwebs... "+
    "another testament to the fact that all care for this place has long since "+
    "ceased.%^RESET%^",]);
    return tmp;
}

mapping picture_items(string hint)
{
    mapping picture_choices, tmp;
    string *pcs;
    int x;
    picture_choices = ([ "skeleton" : ([ "default" : SKEL, "hint" : SKEL_H, ]),
                        "zombie" : ([ "default" : ZOM, "hint" : ZOM_H, ]),
                        "ghoul" : ([ "default" : GHOUL, "hint" : GHOUL_H, ]),
                        "ghost" : ([ "default": GHOST, "hint" : GHOST_H, ]),
                        "werewolf" : ([ "default" : WERE, "hint" : WERE_H, ]),
                        "goblin" : ([ "default" : GOB, "hint" : GOB_H, ]),
                        "hobgoblin" : ([ "default" : HOB, "hint" : HOB_H, ]),
                        "gnoll" : ([ "default" : GNOLL, "hint" : GNOLL_H, ]),]);
    //picture_choices = ([]);

    pcs = keys(picture_choices);
    tmp = ([]);
    for(x = 0;x < sizeof(pcs);x++)
    {
        if(hint == pcs[x]) tmp += ([({pcs[x], "drawing of "+pcs[x], pcs[x] + " drawing"}) : picture_choices[pcs[x]]["hint"],]);        
        else  tmp += ([({pcs[x], "drawing of "+pcs[x], pcs[x] + " drawing"}) : picture_choices[pcs[x]]["default"],]);
    }   
    return tmp;
}

string query_puzzle_description(object room)
{
    object sarc;
    mixed hint;
    mapping tmp;
    string myRoom, ret, let, sol;
    if(!objectp(room)) return "This wrong is broken. Tell Saide.";
    myRoom = base_name(room) + ".c";
    ret = "%^BOLD%^%^BLACK%^You stand within an "+
    "ancient tomb. It is composed from the same %^BOLD%^%^WHITE%^white "+
    "stone%^BOLD%^%^BLACK%^ that the rest of the mausoleum has been "+
    "constructed from. It is also instantly apparent that it too has long since "+
    "been abandoned. There are %^BOLD%^%^WHITE%^cracks%^BOLD%^%^BLACK%^ visible on "+
    "the walls, floor, and ceiling. The entire structure %^BOLD%^%^GREEN%^groans "+
    "%^BOLD%^%^BLACK%^and %^BOLD%^%^GREEN%^creaks%^BOLD%^%^BLACK%^ around you, as it "+
    "wages an unrelenting war against the weight of the %^RESET%^%^ORANGE%^dirt "+
    "%^BOLD%^%^BLACK%^above. There are %^BOLD%^%^YELLOW%^torch holders%^BOLD%^%^BLACK%^ "+
    "on the walls, though they are covered by %^RESET%^%^MAGENTA%^dust"+
    "%^BOLD%^%^BLACK%^ and %^BOLD%^%^WHITE%^cobwebs%^BOLD%^%^BLACK%^. They have long "+
    "been empty.";
    
    if(stringp(hint = is_puzzle_room(myRoom, "word puzzle")))
    {
        ret += "%^BOLD%^%^BLACK%^ There are %^BOLD%^%^YELLOW%^letters%^BOLD%^%^BLACK%^"+
        " scrawled all over the walls, visible "+
        "only because of the dust in which they are written. Most of them have "+
        "faded with time, however, a few are still legible.%^RESET%^";
        if((string)room->query_property("mysolution") != get_puzzle_solution("word puzzle") ||
        (string)room->query_property("mypuzzle") != "word puzzle")
        {
            tmp = default_items();
            let = assign_random_letters(hint);
            tmp += ([({"letters", "walls"}) : "%^BOLD%^%^WHITE%^There are multitudes of "+
            "letters scrawled all over the walls. They are visible only because of the "+
            "dust in which they are written. Most of them have long since faded with the "+
            "unrelenting passage of time. You are able to make out the following "+
            "legibly:\n"+let+"%^RESET%^"]);  
            tmp += ([({"cracks", "crack"}) : (:"crack_description":)]);
            room->remove_property("mypuzzle");
            room->remove_property("mysolution");
            room->set_property("mypuzzle", "word puzzle");
            room->set_property("mysolution", get_puzzle_solution("word puzzle"));
            room->set_items(tmp);
        }
        return ret;
    }
    else if(stringp(hint = is_puzzle_room(myRoom, "number puzzle")))
    {
        ret += "%^BOLD%^%^BLACK%^ There are %^RESET%^%^ORANGE%^numbers %^BOLD%^%^BLACK%^"+
        "written in the thick dust which coats the walls here. They appear randomly all over "+
        "the walls but most of them are so faded from the passage of time that they are "+
        "now illegible.%^RESET%^";
        if((string)room->query_property("mysolution") !=  get_puzzle_solution("number puzzle")
            || (string)room->query_property("mypuzzle") != "number puzzle")
        {
            tmp = default_items();
            let = assign_random_numbers(hint);
            tmp += ([({"numbers", "walls"}) : "%^BOLD%^%^WHITE%^These numbers have been "+
            "written in the thick dust which coats the walls here. They appear randomly all "+
            "over the walls but most of them are so faded from the passage of time that "+
            "they are now illegible. You can only manage to make out the following:\n"+
            let+"%^RESET%^"]);
            tmp += ([({"cracks", "crack"}) : (:"crack_description":)]);
            room->remove_property("mypuzzle");
            room->remove_property("mysolution");
            room->set_property("mysolution", get_puzzle_solution("number puzzle"));
            room->set_property("mypuzzle", "number puzzle");
            room->set_items(tmp);
        }
        return ret;
    }
    else if(stringp(hint = is_puzzle_room(myRoom, "sphere puzzle")))
    {
        ret += "%^BOLD%^%^BLACK%^ There are strange %^RESET%^%^CYAN%^spheres%^BOLD%^%^BLACK%^ "+
        "of various colors engraved into the walls. They constrast quite dramatically with "+
        "the simple %^BOLD%^%^WHITE%^white stone%^BOLD%^%^BLACK%^ of the tomb. "+
        "They have been engraved slightly above "+
        "the %^BOLD%^%^YELLOW%^torch holders%^BOLD%^%^BLACK%^ and you see eight of them "+
        "in total. You get the sense that at some point they held much more meaning than they "+
        "do now, though you have no idea what purpose they might have originally served.%^RESET%^";
        if((string)room->query_property("mysolution") != get_puzzle_solution("sphere puzzle") ||
        (string)room->query_property("mypuzzle") != "sphere puzzle")
        {
            tmp = default_items();
            tmp += ([({"cracks", "crack"}) : (:"crack_description":)]);
            let = assign_random_colors(hint, myRoom);
            tmp += ([({"spheres", "colored spheres"}) : "%^BOLD%^%^WHITE%^These strange spheres "+
            "are of various colors, though they are all exactly the same size. You get the sense "+
            "that some point they served a very important purpose but whatever their "+
            "original intention was it is beyond you. The eight that remain look like the following:"+
            "\n"+let+"%^RESET%^"]);
            
            room->remove_property("mypuzzle");
            room->remove_property("mysolution");
            room->set_property("mysolution", get_puzzle_solution("sphere puzzle"));
            room->set_property("mypuzzle", "sphere puzzle");
            room->set_items(tmp);
        }
        return ret;
    }
    else if(stringp(hint = is_puzzle_room(myRoom, "picture puzzle")))
    {
        ret += "%^BOLD%^%^BLACK%^ There are %^RESET%^%^ORANGE%^drawings%^BOLD%^%^BLACK%^ "+
        "of different creatures covering large portions of the walls. You are unsure of what "+
        "purpose they might serve or what their original meaning was, but they add an air of "+
        "mystery to this tomb.%^RESET%^";
        if((string)room->query_property("mysolution") != get_puzzle_solution("picture puzzle") ||
        (string)room->query_property("mypuzzle") != "picture puzzle")
        {
            tmp = default_items();
            tmp += ([({"cracks", "crack"}) : (:"crack_description":)]);
            let = assign_random_pictures(hint, myRoom);
            tmp += ([({"drawings", "drawing"}) : "%^RESET%^%^ORANGE%^These drawings "+
            "cover large portions of the walls. You see drawings that "+
            "resemble "+let+". You could look at "+
            "each drawing individually if you wanted to do so."]);            
            tmp += picture_items(hint);
            room->remove_property("mypuzzle");
            room->remove_property("mysolution");
            room->set_property("mysolution", get_puzzle_solution("picture puzzle"));
            room->set_property("mypuzzle", "picture puzzle");
            room->set_items(tmp);
        }
        return ret;
    }
    else if(stringp(hint = get_sarcophagus_type(myRoom)))
    {
        ret += "%^BOLD%^%^BLACK%^ There is an elaborately constructed %^BOLD%^%^WHITE%^platform%^BOLD%^"+
        "%^BLACK%^ that rises up in the center of the tomb here. There is a large ornate sarcophagus "+
        "sitting on top of it.%^RESET%^";
        tmp = default_items();
        sol = get_puzzle_solution(hint);
        if((string)room->query_property("mysolution") != sol || (string)room->query_property("mypuzzle") != hint)
        {
            tmp += ([({"cracks", "crack"}) : (:"crack_description":)]);
            if(!objectp(sarc = present("sarcophagus", room))) { sarc = new(MOBJ"sarcophagus"); sarc->move(room); }
            sarc->set_my_puzzle(hint);
            sarc->set_my_solution(sol);          
            room->set_items(tmp);
            room->remove_property("mypuzzle");
            room->remove_property("mysolution");
            room->set_property("mypuzzle", hint);
            room->set_property("mysolution", sol);
        }
    }
    return ret;
}

void clear_dopples()
{
    object dop;
    int x;
    string *names;
    if(!mapp(DOPPLEGANGERS)) return;
    if(!sizeof(keys(DOPPLEGANGERS))) return;
    names = keys(DOPPLEGANGERS);
    for(x = 0;x < sizeof(names);x++)
    {
        if(!objectp(dop = DOPPLEGANGERS[names[x]])) continue;
        dop->remove();        
        continue;
    }
    return;
}

void clean_up()
{
    clear_dopples();
    return ::clean_up();
}

void dopple_ganger(object who)
{
    string *rooms, *names, name, room;
    object dop;
    if(!objectp(who)) return;
    if(!userp(who)) return;
    if(avatarp(who)) return;
    if(!mapp(DOPPLEGANGERS)) DOPPLEGANGERS = ([]);
    names = keys(DOPPLEGANGERS);
    name = who->query_true_name();
    rooms = get_dir(MAUS);
    rooms -= ({"hidden5", "hidden28"});
    if(!sizeof(names))
    {
        dop = new(MMON"doppleganger");
        dop->hunting(who);
        room = rooms[random(sizeof(rooms))];
        room = MAUS + room;
        dop->move(room);
        DOPPLEGANGERS += ([ name : dop]);
        return;
    }
    if(member_array(name, names) != -1)
    {
        if(objectp(dop = DOPPLEGANGERS[name])) return;
        dop = new(MMON"doppleganger");
        dop->hunting(who);
        room = rooms[random(sizeof(rooms))];
        room = MAUS + room;
        dop->move(room);
        DOPPLEGANGERS[name] = dop;
        return;
    }
    else
    {
        dop = new(MMON"doppleganger");
        dop->hunting(who);
        room = rooms[random(sizeof(rooms))];
        room = MAUS + room;
        dop->move(room);
        DOPPLEGANGERS += ([ name : dop]);
        return;
    }
    return;
}

mapping dopples() 
{ 
    int x;
    string *names;
    if(!mapp(DOPPLEGANGERS)) DOPPLEGANGERS = ([]);
    names = keys(DOPPLEGANGERS);
    for(x = 0;x < sizeof(names);x++)
    {
        if(!objectp(DOPPLEGANGERS[names[x]]))
        {
            map_delete(DOPPLEGANGERS, names[x]);
            continue;
        }        
        continue;
    }
    return DOPPLEGANGERS; 
}