/* Copyright 1994 - Tim Hollebeek
 *
 * Permission is granted to copy and use this code elsewhere, provided
 * that all code derived from this code retain this header and credit
 * the author (Tim Hollebeek) for the source, that all improvements
 * to this code be communicated to the above mentioned author for possible
 * inclusion in this code, that all derived works are made publicly
 * available to whoever wants them, and no profit is made off of this
 * code or any other derived works or any other package or system this
 * is used in without express written permission of the author.
 */
/* written quickly by Beek, Oct 12, 1994 */

#include <std.h>
#include <daemons.h>

inherit DAEMON;

private void main_loop();

private void unsubscribe(string);

private void show_headers();
private void post(string, function);

protected void ask_what_next(string);
protected void ask_about_group(string);

#define STRIP_UNSUB(x) ((x) ? ((x)[0] == '#' ? (x)[1..strlen(x)] : x) : 0)
#define IS_UNSUB(x) ((x) && ((x)[0] == '#'))

#define ALL_ARTICLES    1

int options = 0;
object who;
mapping read = ([]);
string *groups;
int *ids;

/* The following code is imported from the first newsreader I ever
   wrote, which is also one of the first LPC objects I ever wrote :)
   It's hideously inefficient and in need of a rewrite, but it will
   do for now */

int included(int id,string read) {
    string *ranges;
    int i,begin,end;

    if (!read) return 0;
    ranges=explode(read,",");
    for (i=0;i<sizeof(ranges);i++) {
        if (sscanf(ranges[i],"%d-%d",begin,end)==2) {
            if ((begin<=id) && (id<=end)) return 1;
        } else {
            sscanf(ranges[i],"%d",begin);
            if (id==begin) return 1;
        }
    }
    return 0;
}

int GetRight(string range) {
    int begin,end;


    if (sscanf(range,"%d-%d",begin,end)==2) return end;
    sscanf(range,"%d",begin);
    return begin;
}

int GetLeft(string range) {
    int begin,end;

    if (sscanf(range,"%d-%d",begin,end)==2) return begin;
    sscanf(range,"%d",begin);
    return begin;
}

string AddToList(string list,int num) {
    string *ranges;
    int i,left,right;

    if (list == "") list = 0;
    if (included(num,list)) return list;

    if (!list) return sprintf("%d",num);
    ranges=explode(list,",");
    for (i=0;i<sizeof(ranges);i++) {
        left=GetLeft(ranges[i]);
        if (num<left) {
            right=-1;
            if (i) right=GetRight(ranges[i-1]);
            if ((right+1==num) && (num==left-1)) {
                ranges[i-1]=sprintf("%d-%d",GetLeft(ranges[i-1]),
                      GetRight(ranges[i]));
                ranges=ranges[0..i-1]+ranges[i+1..(sizeof(ranges)-1)];
            } else if (right+1==num) {
                ranges[i-1]=sprintf("%d-%d",GetLeft(ranges[i-1]),num);
            } else if (num==left-1) {
                ranges[i]=sprintf("%d-%d",num,GetRight(ranges[i]));
            } else {
                ranges=ranges[0..i-1]+({sprintf("%d",
                      num)})+ranges[i..(sizeof(ranges)-1)];
            }
            return implode(ranges,",");
        }
    }

    if (GetRight(ranges[sizeof(ranges)-1])==num-1) {
        ranges[sizeof(ranges)-1]=sprintf("%d-%d",
               GetLeft(ranges[sizeof(ranges)-1]),num;
    } else ranges+=({sprintf("%d",num)});
    return implode(ranges,",");
}
/* end imported code */

/* don't call this on an unsubscribed group */
private void add_read(string group, int id) {
    read[group] = AddToList(read[group], id);
}

private void exit(int aborted) {
    string *groups;
    int i, n;

    if (!aborted)
        write("End of news.");

    unguarded( (: write_file, "/daemon/save/news/rn/"+who->query_name(),
               save_variable(read), 1 :) );
    write_file("/daemon/save/news/rn/"+who->query_name(), save_variable(read),
               1);
    destruct(this_object());
}

private void end_follow(mixed *data) {
    string file;
    string message;
    string group = data[0];
    int id = data[1];

    file = who->query_edit_filename();
    message = read_file(file);
    rm(file);
    NEWSSERVER->followup(group, id, message);
    ask_what_next(0);
}

private void abort_post(function when_done) {
    string file;

    file = who->query_edit_filename();
    if (file && file_exists(file)) rm (file);
    write("Post aborted.");
    evaluate(when_done);
}

private void follow(string group, int id, string insert) {
    string fname = "/tmp/rm."+who->query_name();
    write_file(fname, insert, 1);
    who->edit(fname, (: end_follow :), (: abort_post :), ({ group, id }));
}

private void end_article() {

    printf("End of article -- ");
    ask_what_next(0);
}

private void show_article(int id) {
    string tmp;
    mapping article;

    article = NEWSSERVER->get_message(groups[0], id);
    if (!article["MESSAGE"]) article["MESSAGE"] = "";
    tmp = ({ sprintf("Post %i (%i more) in %s:",
                     ids[0], sizeof(ids)-1, groups[0]),
             "Poster: " + article["POSTER"],
             "Subject: " + article["SUBJECT"] + "",
             "Date: " + ctime(article["TIME"]),"" })+
             explode(article["MESSAGE"], "\n");
    add_read(groups[0], id);
    who->more(tmp, "news", (: end_article :));

}

private string quote_text(string orig) {
 if (orig[strlen(orig)-1] == '\n') orig = orig[0..strlen(orig)-2];
    return "> " + replace_string(orig, "\n", "\n> ") + "\n";
}

private void next_group() {
    groups = groups[1..sizeof(groups)];
    main_loop();
}

protected void ask_what_next(string response) {
    int num;

    switch (response) {
    case "u": /* unsubscribe */
        unsubscribe(groups[0]);
        next_group();
        return;
    case "p":
        post(groups[0], (: ask_what_next, 0 :));
        return;
    case "c": /* catch up */
        {
            int i,n;
            for (i=0, n=sizeof(ids); i<n; i++)
                add_read(groups[0], ids[i]);
        }
        next_group();
        return;
    case "q": /* quit group */
        next_group();
        return;
    case "=": /* list headers */
        show_headers();
        break;
    case "F":
    case "f": /* followup */
        {
            string insert;

            if (ids[0] == -1) {
                write("No current article");
                break;
            }
            insert = "";
            if (response == "F") {
                mapping article = NEWSSERVER->get_message(groups[0], ids[0]);
                insert = sprintf("%s writes:\n%s", article["POSTER"],
                                 quote_text(article["MESSAGE"]));
            }
            follow(groups[0], ids[0], insert);
            return;
        }
    case "?":
    case "h":
        write(@ENDHELP

c - mark all articles in this group as read
f - post followup to last article
F - same as 'f' but include article preceded by "> "
h or ? - this help
n - read next article
p - post an article to this group
q - go back to newsgroup mode
u - unsubscribe to this group
= - list articles remaining in group
a number - read a specified article
ENDHELP);
        break;
    case "":
    case "n":
        if (ids[0] == -1)
            ids = ids[1..sizeof(ids)];
        if (sizeof(ids) > 1) {
            ids = ids[1..sizeof(ids)];
            show_article(ids[0]);
        } else {

            write("End of group " + groups[0] + "\n");
            next_group();
        }
        return;
    default:
        if (response && sscanf(response, "%d", num)) {
            if (member_array(num, NEWSSERVER->get_messages(groups[0])) == -1) {
                write("No such message.");
            } else {
                if (ids[0] == -1)
                    ids[0] = num;
                else
                    ids = ({ num }) + ids;
                show_article(ids[0]);
                return;
            }
        }
    }
    printf("What next? [cfFhnpqu?=] ");
    input_to("ask_what_next");

}

private void show_headers() {
    int i,n;
    mapping article;

    for (n=sizeof(ids); i<n; i++) {
        article = NEWSSERVER->get_message(groups[0], ids[i]);
        printf("[%3d] %-15s %s\n", ids[i], article["POSTER"],
               article["SUBJECT"]);
    }
}

private void unsubscribe(string group) {
    if (read[group])
        read[group] = "#" + read[group];
    else
        read[group] = "#";
}


private void subscribe(string group) {
    read[group] = STRIP_UNSUB(read[group]);
}

private string temp_kludge;

private int *
get_unread(string group) {
    int *ret;

    ret = NEWSSERVER->get_messages(group);
    if (!(options & ALL_ARTICLES)) {
        temp_kludge = STRIP_UNSUB(read[group]);
        ret = filter_array(ret, (: !included($1, temp_kludge) :));
    }
    if (!sizeof(ret)) return 0;
    return ret;
}


private void main_loop() {
    if (!sizeof(groups)) {
        exit(0);
        return;
    }
    ids = get_unread(groups[0]);
    while (!ids) {
        groups = groups[1..sizeof(groups)];
        if (sizeof(groups))
            ids = get_unread(groups[0]);
        else break;
    }
    if (!ids) {
        exit(0);
        return;
    }
    ask_about_group(0);
}


private void start_main_loop() {
    if (!groups)
        groups = NEWSSERVER->get_groups();
    /* remove unsubscribed groups */
    groups = filter_array( groups, (: !read[$1] || read[$1][0] != '#' :) );
    if (!sizeof(groups)) {
        exit(0);
        return;
    }
    main_loop();
}

private void list_groups() {
    string *groups = NEWSSERVER->get_groups();
    int i,n;
    int ur;
    string urs;


    for (i=0, n=sizeof(groups); i<n; i++) {
        ur = sizeof(get_unread(groups[i]));
        urs = (ur ? "(" + ur + ")" : "(READ)");
        if (IS_UNSUB(read[groups[i]]))
            urs = "(UNSUB)";
        printf("%7s %s\n", urs, groups[i]);
    }
}

protected void ask_subscribe(string response, string group) {
    switch (response) {
    case "y":
        subscribe(group);
        groups = ({ group }) + groups;
        main_loop();
        return;
    case "n":
        main_loop();

        return;
    default:
        printf("%s is currently unsubscribed.  Resubscribe? [yn] ", group);
        input_to("ask_subscribe", 0, group);
    }
}

private void goto_group( string group ) {
    if (member_array(group, NEWSSERVER->get_groups()) == -1) {
        write("No such group.");
        ask_about_group(0);
        return;
    }
    if (IS_UNSUB(read[group])) {
        ask_subscribe(0, group);
    } else {
        groups = ({ group }) + groups;
        main_loop();
    }

}

protected void ask_about_group(string response) {
    switch (response) {     /* break; instead of return; goes to next group */
    case "q": /* quit */
        exit(1);
        return;
    case "c": /* catch up */
        {
            int i,n;
            for (i=0, n=sizeof(ids); i<n; i++)
                add_read(groups[0], ids[i]);
            break;
        }
    case "u": /* unsubscribe */
        unsubscribe(groups[0]);
        break;
    case "p":
        post(groups[0], (: ask_about_group, 0 :));
        return;
    case "n": /* next group */
        break;
    case "=": /* show headers */
        show_headers();
        ids = ({ -1 }) + ids;
        ask_what_next(0);
        return;
    case "L": /* list groups */
        list_groups();
        ask_about_group(0);
        return;
    case "h":
    case "?":
        write(@ENDHELP
c - mark all articles in this group as read
h or ? - this help
L - show all groups
n - go on to next group
p - post an article to this group

q - quit rn
u - unsubscribe to this group
y - read first article
= - show articles in group, and start reading
ENDHELP);
        ask_about_group(0);
        return;
    case "y":
    case "": /* show article */
        show_article(ids[0]);
        return;
    default:
        if (response && response[0..1]=="g ") { /* group */
            goto_group(response[2..strlen(response)]);
            return;
        }
        printf("******* %i unread posts in %s -- read now? [chLnpquy?=] ",
sizeof(ids), groups[0]);
        input_to("ask_about_group", 0);
        return;
    }

    next_group();
}

protected void ask_about_new_groups(string response, string *groups_left) {
    int n;

    if (response) {
        read[groups_left[0]] = (response == "y" ? 0 : "#");
        if ((n=sizeof(groups_left)) <= 1) {
            start_main_loop();
            return;
        }
        groups_left = groups_left[1..n];
    }
    printf("group '%s' is new; subscribe? (y/n) >", groups_left[0]);
    input_to("ask_about_new_groups", 0, groups_left);
}

private void load_newsrc(string file, string group) {
    string *new_groups;

    file = read_file(file);
    if (file)
        read = restore_variable(file);
    if (group) {
        if (member_array(group, NEWSSERVER->get_groups()) == -1) {
            write("No such group.");
            return;
        }
        groups = ({ group });
    } else {
        new_groups = (string *)NEWSSERVER->get_groups() - keys(read);
        if (sizeof(new_groups)) {
            ask_about_new_groups(0, new_groups);
            return;
        }
    }
    start_main_loop();

}

private void post(string group, function when_done) {
    if (member_array(group, NEWSSERVER->get_groups()) == -1) {
        write("No such group.");
        return;
    }
    printf("Subject: ");
    input_to("get_subject", 0, group, when_done);
}

private void end_post(string subj, string group, function when_done) {
    string file;
    string message;

    file = who->query_edit_filename();
    message = read_file(file);
    rm(file);

    NEWSSERVER->post(group, subj, message);
    evaluate(when_done);
}

protected void get_subject(string subj, string group, function when_done) {
    who->edit("/tmp/rn."+who->query_name(),
              (: end_post, subj, group, when_done :),
              (: abort_post, when_done :));
}

syntax_error() {
    return notify_fail("rn [-all] [-post] [newsgroup]\n");
}

int start_up( string str ) {
    string *args;
    string gname;
    int n;

    int posting;

    who = this_player();
    if (str) {
        args = explode(str, " ");
        n = sizeof(args);
        while (n && args[0][0]=='-') {
            switch (args[0]) {
            case "-all":
                options |= ALL_ARTICLES;
                break;
            case "-post":
                posting = 1;
                break;
            default:
                write("rn: unknown flag '"+args[0]+"'");
                return 1;
            }
            args = args[1..n--];
        }
        if (n>1)
            return syntax_error();
        if (n)
            gname = args[0];
    }
    if (posting) {
        if (!gname)
            return notify_fail("Must specify group to post to.\n");
        post(gname, 0);
    } else
        load_newsrc("/daemon/save/news/rn/" + this_player()->query_name(), gname);
    return 1;
}
