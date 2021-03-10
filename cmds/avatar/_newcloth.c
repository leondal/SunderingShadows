#include <std.h>
#include <materials.h>

inherit DAEMON;

void make_newcloth(string type, string color, int quality, int quantity)
{
    object obj;
    obj = new("/std/obj/cloth.c");

    if(type == "random")    
    { 
        type = CLOTH_TYPES[random(sizeof(CLOTH_TYPES))];
        color = CLOTH_COLORS[type][random(sizeof(CLOTH_COLORS[type]))];
    }
    if(color == "random")
    {
        color = CLOTH_COLORS[type][random(sizeof(CLOTH_COLORS[type]))];
    }

    if(type && color)
    {
        if(member_array(color,CLOTH_COLORS[type]) == -1)
        {
            write("you must enter a valid color for "
                "cloth type:  "+type+"");
        }
    }

    obj->set_cloth_type_and_color(type,color);
    obj->set_cloth_quality(quality);
    obj->set_cloth_quantity(quantity);

    obj->move(TP);
    write("Done.\n");
    return;
}

void cmd_newcloth(string str) 
{
    object obj;
    string type,color;
    int i,quality,quantity;

    if(!str) 
    { 
        obj = new("/std/obj/cloth.c"); 
        obj->move(TP); 
        write("Done.\n"); 
        return 1; 
    }

    if(sscanf(str,"%s %s %d %d",type,color,quality,quantity) == 4) {}
    else if(sscanf(str,"%s %s %d",type,color,quality) == 3) {}
    else if(sscanf(str,"%s %s",type,color) == 2) {}
    else if(sscanf(str,"%s",type) == 1) {}

    if(type == "cloth?")
    {   
        for(i=0;i<sizeof(CLOTH_TYPES);i++)
        {
            if(!i) { write("Listing valid cloth types:  %^CYAN%^"+CLOTH_TYPES[i]+"%^RESET%^"); }
            else if(i) { write("                            %^CYAN%^"+CLOTH_TYPES[i]+"%^RESET%^"); }
            if(1>1000) { error("loop"); break; }
        }
        return 1;
    }

    if(type && color == "color?")
    {
        if(type == "random")
        {
            write("You must enter a valid cloth type to "
                "use the color? option.  <newcloth cloth?> "
                "for a listing of valid types.");
            return 1;
        }

        if(member_array(type, CLOTH_TYPES) == -1 )
        {
            write("You must enter a valid cloth type or 'random'");
            return 1;
        }

        write("Listing valid colors for cloth type:  %^MAGENTA%^"+type+"%^RESET%^\n");
        for(i=0;i<sizeof(CLOTH_COLORS[type]);i++)
        {                  
            write("                                      %^CYAN%^"+CLOTH_COLORS[type][i]+"%^RESET%^");
            if(1>1000) { error("loop"); break; }
        }
        return 1;
    }

    if(type == "random" && color)
    {
        write("You may not specify a color if you choose "
            "type 'random'");
        return 1;
    }

    if(type != "random" && member_array(type, CLOTH_TYPES) == -1)
    {
        write("You must enter a valid cloth type or 'random'");
        return 1;
    }


    if(type && !color && !quality && !quantity)
    {
        make_newcloth(type,"random",random(10)+1,random(10)+1);
        return 1;
    }
    if(type && color && !quality && !quantity)
    {
        make_newcloth(type,color,random(10)+1,random(10)+1);
        return 1;
    }
    if(type && !color && quality && !quantity)
    {
        make_newcloth(type,color,quality,random(10)+1);
        return 1;
    }
    if(type && color && quality && quantity)
    {
        make_newcloth(type,color,quality,quantity);
        return 1;
    }

    return 1;

}


int help()
{
   write(
@ARES
    syntax: newcloth <type> <color> <quality> <quantity>

    This command allows the creation of new cloth of <type>.
    If no fields are specified, then all fields are random.
    If type is 'cloth?' a list of valid cloth types is
    returned.  If a cloth type is specified and color is
    'color?', a list of valid colors for that cloth is
    returned.

    Examples: newcloth                  - all three fields are random
              newcloth tweed, random 10 - color and quantity fields are random
              newcloth cotton           - color, quality, and quantity are random
              newcloth cloth?           - lists all valid types of cloth
              newcloth cotton color?    - lists valid colors of cotton
    
    Quality 1 = lowest, 10 = highest

ARES
    );
    return 1;
}

