// Created by Ares 09/07/05
// Added titles to the id of the book, to work with the coming library stuff -Ares 09/09/05
#include <std.h>
#include <daemons.h>
#include <security.h>

inherit OBJECT;

mapping __BookData;     // used to keep track of what's on all the pages, global so it can be saved and loaded
string __BookShort;     // will be restored when retrieved from library
string __BookLong = "";      // will be restored when retrieved from library
string __Title;         // used to identify the book in the library
string __AuthorAlias;   // this is to needed for library functions
string __AuthorName;    // more stuff needed for libraries
int __CheckedOut;
int last_page;
int library_book;
int modified;
nosave int current_page;

int stuff(string str);
void set_stuff(string str,string stuff);
void set_author(string alias);
int remove_page(string str);
int turn_page(string str);
int show_contents();
int check_page(string str);
mapping get_page(int page);
int chapter_start_page(string chapter);
void read_page(int page);
void add_page(string chapter,object page);
int set_chapter_page_number(string chapter);
void set_page_numbers();
void set_last_page(int page);
int is_chapter(string chapter);
string *query_chapter_names();
mapping query_chapters();
void set_title(string title);
int invalid_character_check(string str,object player);
int help(string str);
int check_status();
// These are extra functions in case someone needs them later
mapping query_book_data();
string query_book_short();
string query_book_long();
string query_book_title();
int query_last_book_page();
int query_checked_out();
int query_modified();
int query_library_book();
string query_author_name();
string query_author_alias();
void set_book_data(mapping data);
void set_book_short(string str);
void set_book_title(string str);
void set_last_book_page(int num);
void set_checked_out(int num);
void set_modified(int num);
void set_library_book(int num);
void set_author_name(string str);
void set_author_alias(string str);
void check_forgery(object player);
// functions below used to save and restore books
void SAVE(string file);
void RESTORE(string file);


void create()
{
    __BookData = ([]);
    ::create();
    set_id(({"book","bookxxx"}));
    set_name("book");
    set_title("Blank Volume");
    set_short("an empty book");
    set_long("This is an empty book.  There are bindings in the back "
        "that look designed to hold pages. See <help book> for "
        "instructions on how to use the book.");
    set_weight(2);
    set_value(100);
    seteuid(UID_DAEMONSAVE);
}

void init()
{
    ::init();
    set_overallStatus(100);
    add_action("check_page","add");
    add_action("show_contents","contents");
    add_action("turn_page","turn");
    add_action("remove_page","remove");
    add_action("help","help");
    add_action("stuff","set");
    return;
}

string query_long(string str) // override to stick the title on the end, now complete with Author
{
    string hold;
    if(!__AuthorName || __AuthorName == "" || __AuthorAlias == "")
    {
        hold= __BookLong +"\n%^BOLD%^The title on the spine reads%^RESET%^: "+__Title;
        return hold;
    }
    hold= __BookLong+"\n%^BOLD%^The title on the spine reads%^RESET%^: "+__Title+""
        "%^RESET%^ by "+__AuthorAlias+"%^RESET%^";
    return hold;
}

int stuff(string str)
{
    if(!str) { return 0; }
    if(!check_status()) { return 1; }
    str = lower_case(str);
    if(str != "short" &&
       str != "long" &&
       str != "title") { return 0; }
    write("Enter the "+str+" for the book");
    write("Enter ** to abort");
    input_to("set_stuff",str);
    return 1;
}

void set_stuff(string str,string stuff)
{
    if(str == "**") { return; }
    if(!check_status()) { return 1; }
    check_forgery(TP);

    if(!__AuthorName || __AuthorName == "")
    {
        write("%^BOLD%^%^WHITE%^This is the first time this book has been altered.%^RESET%^");
        write("%^BOLD%^%^WHITE%^Please enter the author's alias for this book%^RESET%^");
        write("%^BOLD%^%^WHITE%^Enter <none> without the <>'s for no alias%^RESET%^");
        write("%^BOLD%^%^WHITE%^Enter ** to abort%^RESET%^");
        input_to("set_author",str);
    }

    switch(stuff)
    {
    case "short":
        __BookShort = str;
        set_short(__BookShort);
        tell_object(TP,"%^BOLD%^Short description set to:\n %^RESET%^"+__BookShort+"");
        break;
    case "long":
        __BookLong = str;
        set_long(__BookLong);
        tell_object(TP,"%^BOLD%^Description set to:\n %^RESET%^"+__BookLong+"");
        break;
    case "title":
        if(query_library_book())
        {
            if(__Title || __Title != "" && __AuthorName)
            {
                if((string)TP->query_name() != __AuthorName)
                {
                    tell_object(TP,"%^BOLD%^You can't change the title, you are "
                        "not the book's author.%^RESET%^");
                    return;
                }
            }
        }
        if(!invalid_character_check(str,TP)) { return 1; }
        __Title = str;
        set_title(__Title);
        tell_object(TP,"%^BOLD%^Title changed to:\n %^RESET%^"+__Title+"");
        break;
    }
    return 1;
}

void set_author(string alias)
{
    if(alias == "**")   { return; }
    if(alias == "")     { return; }
    if(!check_status()) { return; }

    if(!invalid_character_check(alias,TP)) { return 1; }
    if(strlen(alias) > 25)
    {
        tell_object(TP,"The author alias may not be more than 25 characters long.");
        return 1;
    }

    switch(alias)
    {
    case "none":
        __AuthorAlias = "Anonymous";
        __AuthorName = (string)TP->query_name();
        tell_object(TP,"%^RESET%^%^BOLD%^No author's alias set.%^RESET%^\n");
        break;
    default:
        __AuthorAlias = alias;
        __AuthorName = (string)TP->query_name();
        tell_object(TP,"%^RESET%^%^BOLD%^Author's alias set to:\n %^RESET%^"+__AuthorAlias+"");
        break;
    }
    return 1;
}

int remove_page(string str)
{
    mapping chapters,pages,numbers,new_page;
    string *chap_keys=({}),*page_keys=({}),new_keys=({}),tmp;
    object ob;
    int i,j,page;

    if(!str) { return 0; }
    if(sscanf(str,"page %d",page) != 1) { return 0; }
    if(!check_status()) { return 1; }
    check_forgery(TP);  // see the function

    chapters = query_chapters();
    chap_keys = keys(chapters);
    for(i=0;i<sizeof(chap_keys);i++)
    {
        pages = chapters[chap_keys[i]];
        page_keys = keys(pages);
        for(j=0;j<sizeof(pages);j++)
        {
            numbers = pages[page_keys[j]];
            if(numbers["page"][0] == page )
            {
                new_page = pages[page_keys[j]];
                map_delete(pages,page_keys[j]);
                if(!sizeof(keys(chapters[chap_keys[i]]))) { map_delete(chapters,chap_keys[i]); }
                break;
            }
        }
    }
    if(!new_page) { return notify_fail("There is no page: "+page+"."); }
    new_keys = keys(new_page);
    ob = new("/d/common/obj/misc/paper.c");
    for(i=0;i<sizeof(new_keys);i++)
    {
        if(new_keys[i] == "page") { continue; }
        if(new_page[new_keys[i]][0] == "wizish") { continue; }
        ob->set("language",new_page[new_keys[i]][0]);
        ob->set("read",new_page[new_keys[i]][1]);
    }
    ob->move(TP);

    set_page_numbers();
    tell_room(ETP,"%^BOLD%^"+TP->QCN+" tears a page from "+__Title+".%^RESET%^",TP);
    tell_object(TP,"%^BOLD%^You tear page "+page+" out of "+__Title+".%^RESET%^");

    return 1;
}

int turn_page(string str)
{
    int num;
    string page;
    if(!check_status()) { return 1; }

    if(sscanf(str, "to page %d",num) == 1)
    {
        if(!last_page) { return 1; }
        if(num < 1) { num = 1; }
        if(num > last_page) { num = last_page; }
        current_page = num;
        read_page(current_page);
        tell_room(ETP,"%^BOLD%^"+TP->QCN+" opens up "+__Title+"%^RESET%^%^BOLD%^ "
            "and turns to a page.%^RESET%^",TP);
        tell_object(TP,"%^BOLD%^You open up "+__Title+"%^RESET%^%^BOLD%^ and "
            "turn to page "+num+".%^RESET%^");

        return 1;
    }
    if(sscanf(str,"%s back",page) == 1)
    {
        if(!last_page) { return 1; }
        current_page--;
        if(current_page < 1) { current_page = 1; }
        read_page(current_page);
        tell_room(ETP,"%^BOLD%^"+TP->QCN+" flips back through the "
            "pages of "+__Title+".%^RESET%^",TP);
        tell_object(TP,"%^BOLD%^You flip back through the pages "
            "of "+__Title+".%^RESET%^");
        return 1;
    }
    if(sscanf(str,"%s",page) == 1)
    {
        if(!last_page) { return 1; }
        if(lower_case(page) != "page") { return 0; }
        current_page++;
        if(current_page > last_page) { current_page = last_page; }
        read_page(current_page);
        tell_room(ETP,"%^BOLD%^"+TP->QCN+" flips forward through the "
            "pages of "+__Title+".%^RESET%^",TP);
        tell_object(TP,"%^BOLD%^You flip forward through the pages "
            "of "+__Title+".%^RESET%^");
        return 1;
    }

    return 0;
}

// Such a messy way to sort stuff -Ares
int sort_chapters(string one,string two)
{
    string tmp1,tmp2;
    int len1,len2,num1,num2;
    one = FILTERS_D->filter_colors(one);
    two = FILTERS_D->filter_colors(two);
    len1 = strlen(one);
    len2 = strlen(two);
    tmp1 = one[41..len1];
    tmp2 = two[41..len2];
    num1 = to_int(tmp1);
    num2 = to_int(tmp2);
    if((num1 - num2) < 0)       { return -1; }
    else if((num1 - num2) == 0) { return 0; }
    else return 1;
}

int show_contents()
{
    string *chapters,*display=({});
    int i,page,center;
    if(!objectp(TP)) { return 1; }
    if(!check_status()) { return 1; }
    chapters = query_chapter_names();

    if(!sizeof(chapters)) { return notify_fail("The book is still empty!\n"); }

    center = strlen(FILTERS_D->filter_colors(__Title));
    center = 33 - center;
    center = center/2;

    for(i=0;i<sizeof(chapters);i++)
    {
        display += ({ arrange_string(chapters[i],35) +"%^BOLD%^page%^RESET%^: %^CYAN%^"+chapter_start_page(chapters[i])+"%^RESET%^"});
    }
    chapters = sort_array(display, "sort_chapters",TO);

    set("language","wizish");
    set("read","\n%^BOLD%^%^BLUE%^=-=-=-=-=-=-=-=-=> %^RESET%^"+arrange_string(" ",center)+__Title+arrange_string(" ",center)+"%^BOLD%^%^BLUE%^ <=-=-=-=-=-=-=-=-=%^RESET%^");
    for(i=0;i<sizeof(chapters);i++)
    {
        set("read","\t"+chapters[i]+"");
    }
    set("read","%^BOLD%^%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-%^RESET%^");
    TP->force_me("read bookxxx");
    delete("language list");
    delete("read");
    return 1;
}

int check_page(string str)
{
    object page;
    page = present(str,TP);
    if(!objectp(page))
    {
        return notify_fail(""+str+" not in your inventory, try add paper, add paper 2,etc");
    }
    if(!check_status()) { return 1; }
    if(page->id("component")) { return notify_fail("You can't put that in a book."); }
    if(!page->id("paper") && !page->id("parchment")) { return notify_fail("You can't put that in a book!\n"); }

    write("Please enter the name of the chapter that "
        "the page should go in, if that chapter doesn't "
        "exist, it will be created.  Chapter names "
        "%^RED%^ARE%^RESET%^ case sensative.");
    write("Enter ** to abort.");
    input_to("add_page",page);

    return 1;
}

mapping get_page(int page)
{
    mapping chapters,pages,numbers;
    string *chap_keys=({}),*page_keys=({});
    int i,j;

    chapters = query_chapters();
    chap_keys = keys(chapters);
    for(i=0;i<sizeof(chap_keys);i++)
    {
        pages = chapters[chap_keys[i]];
        page_keys = keys(pages);
        for(j=0;j<sizeof(pages);j++)
        {
            numbers = pages[page_keys[j]];
            if(numbers["page"][0] == page ) { return numbers; }
        }
    }
    return ([]);
}

int chapter_start_page(string chapter)
{
    mapping chapters,pages,numbers;
    string *page_keys;

    if(member_array(chapter,query_chapter_names()) == -1) { return -1; }
    chapters = query_chapters();
    pages = chapters[chapter];
    page_keys = keys(pages);
    if(!sizeof(page_keys)) { return -1; }
    numbers = pages[page_keys[0]];
    return numbers["page"][0];
}

void read_page(int page)
{
    mapping page_data;
    mixed writing;
    string page_num;
    int i,center;
    if(!objectp(TP)) { return; }

    page_data = get_page(page);
    page_num = page_data["page"][0];

    center = strlen(FILTERS_D->filter_colors(__Title));
    center = 33 - center;
    center = center/2;
    writing = keys(page_data);

    set("language","wizish");
    set("read","\n%^BOLD%^%^BLUE%^=-=-=-=-=-=-=-=-=> %^RESET%^"+arrange_string(" ",center)+__Title+arrange_string(" ",center)+"%^BOLD%^%^BLUE%^ <=-=-=-=-=-=-=-=-=%^RESET%^");
    for(i=0;i<sizeof(writing);i++)
    {
        if(writing[i] == "page") { continue; }
        set("language",page_data[writing[i]][0]);
        set("read",page_data[writing[i]][1]);
    }
    set("language","wizish");
    set("read","\t\t\t %^BOLD%^Page%^RESET%^: %^CYAN%^"+page+"%^RESET%^");
    set("language","wizish");
    set("read","%^BOLD%^%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-%^RESET%^");
    TP->force_me("read bookxxx");
    delete("language list");
    delete("read");
    return;
}

void add_page(string chapter,object page)
{
    mapping chapters=([]),page_data=([]);
    string *languages=({}),*writings=({});
    int i;

    if(!page->query("language list")) { return notify_fail("No blank pages allowed.\n"); }
    if(!page->query("read"))          { return notify_fail("No blank pages allowed.\n"); }
    if(!stringp(chapter))             { return notify_fail("You must enter a chapter name.\n"); }
    if(chapter == "**")               { return; }
    if(!is_chapter(chapter))          { __BookData[chapter] = ([]); }
    chapters = __BookData[chapter];
    check_forgery(TP);

    languages += ({ "wizish" }); // just in case we want the chapter name in a language later
    languages += page->query("language list");
    writings  += ({ "\t\t\t%^BOLD%^"+chapter+"%^RESET%^\n" });
    writings  += page->query("read");

    page_data["page"] = ({ 0 });

    for(i=0;i<sizeof(writings);i++)
    {
        page_data[i] = ({ languages[i] , writings[i] });
    }

    chapters += ([ set_chapter_page_number(chapter) : page_data ]);
    set_page_numbers();

    tell_room(ETP,"%^BOLD%^"+TP->QCN+" adds a page to "+__Title+".%^RESET%^",TP);
    tell_object(TP,"%^BOLD%^You add a page to "+__Title+".%^RESET%^");
    page->remove();

    return;
}

int set_chapter_page_number(string chapter)
{
    return sizeof(keys(__BookData[chapter])) + 1;
}

void set_page_numbers()
{
    mapping chapters,pages,numbers;
    string *chap_keys=({}),*page_keys=({});
    int i,j,count;

    chapters = query_chapters();
    chap_keys = keys(chapters);
    for(i=0;i<sizeof(chap_keys);i++)
    {
        pages = chapters[chap_keys[i]];
        page_keys = keys(pages);
        for(j=0;j<sizeof(page_keys);j++)
        {
            count++;
            numbers = pages[page_keys[j]];
            numbers["page"] = ({ count });
        }
        set_last_page(count);
    }
    return;
}

void set_last_page(int page)
{
    last_page = page;
    return;
}

int is_chapter(string chapter)
{
    string *chapters=({});
    chapters = keys(__BookData);
    if(!sizeof(chapters)) { return 0; }
    if(member_array(chapter,chapters) != -1) { return 1; }
    return 0;
}

string *query_chapter_names()
{
    string *chapters=({});
    chapters = keys(__BookData);
    return chapters;
}

mapping query_chapters()
{
    return __BookData;
}

void set_title(string title)
{
    if(!title) { return; }
    __Title = title;
    return;
}

int invalid_character_check(string str,object player)
{
    string *bad_chars,chars;
    int i;
    if(!stringp(str))       { return 0; }
    if(!objectp(player))    { return 0; }
    chars = "* / \ , . # $ % ^ & ~ ' _ = -";
    bad_chars = explode(chars," ");
    str = FILTERS_D->filter_colors(str);
    for(i=0;i<sizeof(bad_chars);i++)
    {
        if(strsrch(str,bad_chars[i]) != -1)
        {
            tell_object(player,"The characters "+chars+" are not valid in "
                "the titles or author alias' of books.");
            return 0;
        }
    }
    return 1;
}

int help(string str)
{
    string tmp;

    if(!str)                            { return 0; }
    if(sscanf(str,"%s",tmp) != 1)       { return 0; }
    if(tmp != "book" && tmp != "books") { return 0; }

   write(
"%^CYAN%^BOOKS%^RESET%^
This book can be used to store papers, both for the purpose of organization, and to create meaningful tomes of information. The following functions are available:

%^ORANGE%^<add %^ORANGE%^%^ULINE%^PAGE%^RESET%^%^ORANGE%^>%^RESET%^
  Where %^ORANGE%^%^ULINE%^PAGE%^RESET%^ is a sheet of paper or parchment in your inventory. You will be prompted to enter the name of the chapter the page belongs in. Chapter names can be anything you choose. Spelling and capitalization must be exact for adding additional pages into the chapter.

%^ORANGE%^<remove page %^ORANGE%^%^ULINE%^NUMBER%^RESET%^%^ORANGE%^>%^RESET%^
  Will remove the page %^ORANGE%^%^ULINE%^NUMBER%^RESET%^ from the book and return it to your inventory.

%^ORANGE%^<turn page>%^RESET%^
  Will flip forward through the pages from your current page.

%^ORANGE%^<turn page back>%^RESET%^
  Will flip backwards through the pages from your current page.

%^ORANGE%^<turn to %^ORANGE%^%^ULINE%^NUMBER%^RESET%^%^ORANGE%^>%^RESET%^
  Will turn to the page number you specify with %^ORANGE%^%^ULINE%^PAGE%^RESET%^.

%^ORANGE%^<set long>%^RESET%^
  Will set the long description of the book, what you see when looking at it. This can only be done once.

%^ORANGE%^<set short>%^RESET%^
  Will set the short description of the book, what is seen in your inventory. This can only be done once.

%^ORANGE%^<set title>%^RESET%^
  Will change the title of the book. It can be changed as many times as necessary.

%^ORANGE%^<contents>%^RESET%^
  Will list the contents of the book by chapter. The page number the chapter starts on will also be displayed.

%^ULINE%^%^CYAN%^About Authors%^RESET%^
When the book is modified for the first time you will be prompted to enter the author's alias. You will be recognized as the author of the book regardless of what alias you enter. This is for use with libraries which will allow you to continue to modify your own books at a later time.
");

   return 1;
}


int check_status()
{
    if(TP->query_bound() || TP->query_unconcious() || TP->query_paralyzed() || TP->query_tripped())
    {
        TP->send_paralyzed_message("info",TP);
        return 0;
    }
    if (TP->query_blind())
    {
        notify_fail("You are blind and cannot see anything.\n");
        return 0;
    }
    return 1;
}

//This is here so when/if the forgery nwp goes in game, it will be easy to
//alter to take it into account

void check_forgery(object player)
{
    if(!objectp(player)) { return; }
    if(query_library_book()) { set_modified(1); }
    return;
}

// These functions here just in case somebody wants to use them for something later
mapping query_book_data()  { if(!__BookData)   { return ([]); }         return __BookData; }
string query_book_short()  { if(!__BookShort)  { return ""; }           return __BookShort; }
string query_book_long()   { if(!__BookLong)   { return ""; }           return __BookLong; }
string query_book_title()  { if(!__Title)      { return ""; }           return __Title; }
int query_last_book_page() { if(!last_page)    { return 0; }            return last_page; }
int query_checked_out()    { if(!__CheckedOut) { return 0; }            return __CheckedOut; }
int query_modified()       { if(!modified)     { return 0; }            return modified; }
int query_library_book()   { if(!library_book) { return 0; }            return library_book; }
string query_author_name() { if(!__AuthorName) { return ""; }           return __AuthorName; }
string query_author_alias(){ if(!__AuthorAlias){ return "Anonymous"; }  return __AuthorAlias; }

void set_book_data(mapping data)  { if(mapp(data))   { __BookData = data; }   return; }
void set_book_short(string str)   { if(stringp(str)) { __BookShort = str; }   return; }
void set_book_title(string str)   { if(stringp(str)) { __Title = str; }       return; }
void set_last_book_page(int num)  { if(intp(num))    { last_page = num; }     return; }
void set_checked_out(int num)     { if(intp(num))    { __CheckedOut = num; }  return; }
void set_modified(int num)        { if(intp(num))    { modified = num; }      return; }
void set_library_book(int num)    { if(intp(num))    { library_book = num; }  return; }
void set_author_name(string str)  { if(stringp(str)) { __AuthorName = str; }  return; }
void set_author_alias(string str) { if(stringp(str)) { __AuthorAlias = str; } return; }

void SAVE(string file)
{
    seteuid(UID_DAEMONSAVE);
    save_object(file);
    return;
}

void RESTORE(string file)
{
    seteuid(UID_DAEMONSAVE);
    restore_object(file);
    return;
}
