#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

char *strcasestr(const char *haystack, const char *needle)
{
    if (!*needle)
        return (char *)haystack;

    for (; *haystack; ++haystack)
    {
        const char *h = haystack;
        const char *n = needle;
        while (*h && *n && tolower(*h) == tolower(*n))
        {
            ++h;
            ++n;
        }
        if (!*n)
            return (char *)haystack;
    }
    return NULL;
}

struct LinkNode
{
    char url[200];
    LinkNode *next;
};
    
int totalLinksVisited = 0;
const int MAX_LINKS = 10;
const int MAX_DEPTH = 2;

bool isHTMLLink(char *url)
{
    int len = strlen(url);
    if (len >= 4)
    {
        if (strcmp(&url[len - 4], ".pdf") == 0)
            return false;
        if (strcmp(&url[len - 4], ".jpg") == 0)
            return false;
        if (strcmp(&url[len - 4], ".png") == 0)
            return false;
        if (strcmp(&url[len - 4], ".css") == 0)
            return false;
        if (strcmp(&url[len - 3], ".js") == 0)
            return false;
    }
    return true;
}

void normalizeURL(char *base, char *url, char *result)
{
    if (strncmp(url, "http", 4) == 0)
    {
        strcpy(result, url);
    }
    else if (url[0] == '/')
    {
        strcpy(result, base);
        strcat(result, url);
    }
    else
    {
        strcpy(result, base);
        strcat(result, "/");
        strcat(result, url);
    }
}
LinkNode *extractLinksToList(char html[], int max_links)
{
    LinkNode *head = NULL, *tail = NULL;
    int i = 0, count = 0;

    ofstream fout("links.txt", ios::app);
    if (!fout)
    {
        cout << "Error opening links.txt to write." << endl;
        return NULL;
    }

    while (html[i] != '\0' && count < max_links)
    {
        if (tolower(html[i]) == '<' && tolower(html[i + 1]) == 'a')
        {
            char *href = strcasestr(&html[i], "href=");
            if (href)
            {
                char quote = href[5];
                if (quote == '\"' || quote == '\'')
                {
                    char *start = strchr(href, quote);
                    if (start)
                    {
                        char *end = strchr(start + 1, quote);
                        if (end)
                        {
                            int len = end - (start + 1);
                            if (len > 0 && len < 250)
                            {
                                char temp[300];
                                strncpy(temp, start + 1, len);
                                temp[len] = '\0';

                                if (isHTMLLink(temp))
                                {
                                    cout << "Found link: " << temp << endl;

                                    fout << temp << endl;

                                    LinkNode *node = new LinkNode;
                                    strcpy(node->url, temp);
                                    node->next = NULL;
                                    if (!head)
                                        head = tail = node;
                                    else
                                    {
                                        tail->next = node;
                                        tail = node;
                                    }
                                    count++;
                                }
                            }
                            i = end - html;
                        }
                    }
                }
            }
        }
        i++;
    }

    fout.close();
    return head;
}
void crawl(char *url, int depth)
{
    if (depth > MAX_DEPTH || totalLinksVisited >= MAX_LINKS)
        return;

    cout << "Crawling: " << url << " at depth " << depth << endl;

    char command[500];
    sprintf(command, "wget \"%s\" -O temp.html", url);
    system(command);

    ifstream file("temp.html");
    if (!file)
    {
        cout << "Failed to download: " << url << endl;
        return;
    }

    char html[10000];
    file.read(html, sizeof(html));
    int len = file.gcount();
    html[len] = '\0';
    file.close();

    LinkNode *links = extractLinksToList(html, 10);
    LinkNode *temp = links;

    while (temp && totalLinksVisited < MAX_LINKS)
    {
        char fullurl[300];
        normalizeURL(url, temp->url, fullurl);

        totalLinksVisited++;
        crawl(fullurl, depth + 1);

        temp = temp->next;
    }

    while (links)
    {
        LinkNode *next = links->next;
        delete links;
        links = next;
    }
}

void crawlFromHTML(char *baseURL, char *html)
{
    totalLinksVisited = 0;
    LinkNode *head = extractLinksToList(html, 100);
    LinkNode *temp = head;

    while (temp && totalLinksVisited < MAX_LINKS)
    {
        char fullurl[300];
        normalizeURL(baseURL, temp->url, fullurl);
        totalLinksVisited++;
        crawl(fullurl, 1);
        temp = temp->next;
    }

    while (head)
    {
        LinkNode *next = head->next;
        delete head;
        head = next;
    }
}