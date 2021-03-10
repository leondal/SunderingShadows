// Update of the _minfo command to show more detailed information about what
// objects are using the most memory. -Ares
#include <std.h>
#include <daemons.h>

string header() { return ({ "%^RESET%^%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=- %^RESET%^%^YELLOW%^Memory Statistics%^RESET%^%^BLUE%^ -=-=-=-=-=-=-=-=-=-=-=-=-\n\n" }); }
string footer() { return ({ "\n\n%^RESET%^%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" }); }

int compare(string one, string two) 
{
    int x,y;
    one = one[64..strlen(one)];
    two = two[64..strlen(two)];
    x = to_int(one);
    y = to_int(two);
    return (y - x);
}

int cmd_memory(string str)
{
    mapping stuff = ([]);
    object *obs,ob;
    string *display=({}),*items=({}),name;
    int i,num,mem;

    obs = objects();
    obs -= ({0});

    for(i=0;i<sizeof(obs);i++)
    {
        if(!objectp(obs[i])) { continue; }

        name = base_name(obs[i]);
        name = FILTERS_D->filter_colors(name);
	  //Added by Saide to allow for 
	  //searching for a particular directory
	  if(strsrch(name, str) == -1 && str) continue;
        if(!(stuff[name])) { stuff[name] = 1; }
        else 
        {
            num = stuff[name];
            num += 1;
            stuff[name] = num;
        }
    }

    items = keys(stuff);

    for(i=0;i<sizeof(items);i++)
    {
        name = items[i];
        num = stuff[name];

        ob = to_object(name);
        if(objectp(ob)) { mem = memory_info(find_object_or_load(name)); }
        else { mem = -1; }
        mem = mem * num;

        display += ({ "   "+arrange_string(name,50)+"  "+arrange_string(""+num+"",9)+""+mem+"" });
    }

    display = sort_array(display,"compare",TO);
    display = ({ "%^RESET%^%^BOLD%^   "+arrange_string("File Name",50)+"  Count   Memory Usage\n" }) + display;
    display = header() + display;
    display += footer();
    TP->more(display);

    return 1;
}