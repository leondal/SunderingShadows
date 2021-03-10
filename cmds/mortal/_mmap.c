#include <std.h>
#include <daemons.h>

#define TWIDTH 3

inherit DAEMON;

mixed * map;
int dim;

nosave mapping topology;
nosave string * topoexits;
nosave mapping exitsymbols;

int cmd_mmap(string str)
{
    int x;
    if(TP->query_blind())
    {
        tell_object(TP, "You are blind.");
        return 0;
    }

    if((x=TP->light_blind(0)))
    {
        tell_object(TP, TP->light_blind_fail_message(x));
        return 0;
    }
    dim=atoi(str);
    if(!dim)
        dim = 5;
    dim=dim-dim%2+1;
    dim = dim>15?15:dim;
    dim = dim<3?3:dim;

    init_topology();
    make_map();

    display_map();
    return 1;
}

void init_topology()
{
    topology=(["west":({-1,0}),
               "east":({1,0}),
               "north":({0,-1}),
               "south":({0,1}),
               "northwest":({-1,-1}),
               "northeast":({1,-1}),
               "southwest":({-1,1}),
               "southeast":({1,1})]);
    topoexits=keys(topology);
    exitsymbols=(["west":"-",
                  "east":"-",
                  "north":"|",
                  "south":"|",
                  "northwest":"\\",
                  "northeast":"/",
                  "southwest":"/",
                  "southeast":"\\"]);
}

void make_map()
{
    int i;

    map = allocate(dim*TWIDTH);
    for(i=0;i<dim*TWIDTH;++i)
        map[i]=allocate(dim*TWIDTH,(:"%^BOLD%^%^BLACK%^.":));

    make_tile(ETP,dim/2,dim/2,".");
}

void make_tile(object room, int x, int y, string from)
{
    string *exits,exit,door;
    string tr_color; //this room color
    string e_color,e_symb; //exit color, exit symbol
    if(!room)
        return;
    catch(exits = room->query_exits());
    if(!exits)
        return;

    if(x<0||y<0||y>(dim-1)||x>(dim-1))
        return;
    if(!room)
        return;

    tr_color="%^MAGENTA%^";
    e_color="%^GREEN%^";

    if(room->query_property("no peer")&&from!=".")
    {
        map[x*TWIDTH+1][y*TWIDTH+1]="%^BOLD%^%^BLACK%^?%^RESET%^";
        return;
    }

    foreach(exit in exits)
    {
        if(arrayp(topology[exit]))
        {
            e_symb=exitsymbols[exit];
            e_color="%^GREEN%^";
            if((door=(string)room->query_door(exit)) && !room->query_open(door))
            {
                e_symb="#";
                e_color = "%^BLUE%^";
            } else
                if(from=="."||from==exit)
                    make_tile(room->query_exit(exit),x+topology[exit][0],y+topology[exit][1],exit);
            map[x*TWIDTH+1+topology[exit][0]][y*TWIDTH+1+topology[exit][1]]="%^RESET%^"+e_color+e_symb+"%^RESET%^";

        } else
            tr_color="%^RED%^";
    }
    if(from==".")
        tr_color="%^ORANGE%^";
    if(sizeof(exits)>0)
        map[x*TWIDTH+1][y*TWIDTH+1]="%^BOLD%^"+tr_color+(sizeof(exits)>9?"?":sizeof(exits))+"%^RESET%^";

}
void display_map()
{
    string line;
    int i,j;
    hline();
    for(i=0;i<dim*TWIDTH;i++)
    {
        line="";
        for(j=0;j<dim*TWIDTH;j++)
        {
            line+=sprintf("%s",map[j][i]);
        }
        write(line);
    }
    hline();
}

void hline()
{
    string line;
    int i;
    line="%^BLUE%^";
    for (i=0; i<dim; ++i)
    {
        line+="-=-";
    }
    line+="%^RESET%^";
    write(line);
}

void help()
{
    write("
%^CYAN%^NAME%^RESET%^

mmap - look around

%^CYAN%^SYNOPSIS%^RESET%^

mmap %^ORANGE%^%^ULINE%^DISTANCE%^RESET%^

%^CYAN%^DESCRIPTION%^RESET%^

Attempts to display a minimap on a grid, based on your peer data.

Numbers display how many exits a room has, red color indicates room has non-standart exits.

%^CYAN%^SEE ALSO%^RESET%^

peer, map, look, glance
");
}
