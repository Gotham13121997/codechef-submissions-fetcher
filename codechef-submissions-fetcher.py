import  bs4 as bs
import urllib.request
import os
import itertools, sys
opener=urllib.request.build_opener()
opener.addheaders = [('User-agent', 'Mozilla/5.0')]
supported_languages={'All':'All','ADA': '1', 'ASM': '2', 'BASH': '3', 'BF': '4', 'C': '5', 'C#': '6', 'C++': '7', 'C++ 4.0.0-8': '8', 'C++ 4.3.2': '9', 'C++ 4.8.1': '10', 'C++ 4.9.2': '11', 'C++ 6.3': '12', 'C++ g++-4.1': '13', 'C++ MPI': '14', 'C++14': '16', 'C++11': '15', 'C99 strict': '17', 'CAML': '18', 'CLOJ': '19', 'CLIPS': '20', 'D': '21', 'ERL': '22', 'F#': '23', 'FORT': '24', 'GO': '25', 'HASK': '26', 'ICK': '27', 'ICON': '28', 'JAR': '29', 'JAVA': '30', 'JS': '31', 'kotlin': '32', 'LISP clisp': '33', 'LISP sbcl': '34', 'LUA': '35', 'NEM': '36', 'NICE': '37', 'NODEJS': '38', 'PAS fpc': '39', 'PAS gpc': '40', 'PERL': '41', 'PERL6': '42', 'PHP': '43', 'PIKE': '44', 'PRLG': '45', 'PYPY': '46', 'PYTH': '47', 'PYTH 3.1.2': '48', 'PYTH 3.4': '49', 'PYTH 3.5': '50', 'RUBY': '51', 'rust': '52', 'SCALA': '53', 'SCM chicken': '54', 'SCM guile': '55', 'SCM qobi': '56', 'ST': '57', 'swift': '58', 'TCL': '59', 'TEXT': '60', 'WSPC': '61'}
status_dict={'All':'All','AC':'15','WA':'14','TLE':'13','RTE':'12','CTE':'11'}
language="C++14" #USE ONLY THE KEYS FROM SUPPORTED LANGUAGES above WITH THE SAME CASE eg. use kotlin not KOTLIN
status="AC" #USE ONLY THE KEYS FROM status_dict
year="2017" #from 2009 to CURRENT YEAR
handle="gotham13" #YOUR HANDLE
problem_code=""#PROBLEM CODE
contest_code=""#CONTEST CODE
languagedict={'ADA':'.ada', 'ASM':'.asm','BASH': '.sh','BF':'.bf','C':'.c','C#':'cs','C++':'cpp','C++ 4.0.0-8':'.cpp','C++ 4.3.2':'.cpp','C++ 4.8.1':'.cpp','C++ 4.9.2':'.cpp','C++ 6.3':'.cpp','C++ g++-4.1':'.cpp','C++ MPI':'.cpp',
              'C++14':'.cpp','C++11':'.cpp','C99 strict':'.c','CAML':'.ml','CLOJ':'.clj','CLIPS':'.clp','D':'.d','ERL':'.erl','F#':'.fs','FORT':'.F','GO':'.go','HASK':'.hs','ICK':'.i',
              'ICON':'.ICN','JAR':'.jar','JAVA':'.java','JS':'.js','kotlin':'.kt','LISP clisp':'.lisp','LISP sbcl':'.lisp','LUA':'.lua','NEM':'.n','NICE':'.nice','NODEJS':'.js','PAS fpc':'.pas',
              'PAS gpc':'.pas','PERL':'.pl','PERL6':'.pl','PHP':'.php','PIKE':'.pike','PRLG':'.prolog','PYPY':'.py','PYTH':'.py','PYTH 3.1.2':'.py','PYTH 3.4':'.py','PYTH 3.5':'.py',
              'RUBY':'.rb','rust':'.rs','SCALA':'.scala','SCM chicken':'.scm','SCM guile':'.scm','SCM qobi':'.scm','ST':'.st','swift':'.swift','TCL':'.tcl','TEXT':'.txt','WSPC':'.ws'}
subs=[]
subs1=[]
subs2=[]
print("working............")
try:
    source = opener.open(
        "https://www.codechef.com/submissions?sort_by=All&sorting_order=asc&language=" + supported_languages[
            language] + "&status=" + status_dict[
            status] + "&year=" + year + "&handle=" + handle + "&pcode=" + problem_code + "&ccode=" + contest_code + "&Submit=GO")
    soup = bs.BeautifulSoup(source, 'html5lib')
    s = soup.find_all('tr', {"class": '\\"kol\\"'})
    for i in s:
        if i.find('div').text=="No Recent Activity":
            print("No submissions")
            os._exit(0)
        if not i.find('a', {"class": "disabled"}):
            subs1.append(i.find('td', {"width": "110"}).text)
            subs.append(i.find('td', {"width": "60"}).text)
            subs2.append(i.find('td', {"width": "109"}).text.strip(" "))

    if soup.find('div', {"class": "pageinfo"}):
        pages = soup.find('div', {"class": "pageinfo"}).text.split(' ')
        endpage = int(pages[len(pages) - 1])
        for j in range(1, endpage):
            source2 = opener.open(
                "https://www.codechef.com/submissions?page=" + str(j) + "sort_by=All&sorting_order=asc&language=" +
                supported_languages[language] + "&status=" + status_dict[
                    status] + "&year=" + year + "&handle=" + handle + "&pcode=" + problem_code + "&ccode=" + contest_code + "&Submit=GO")
            soup2 = bs.BeautifulSoup(source2, 'html5lib')
            s2 = soup2.find_all('tr', {"class": '\\"kol\\"'})
            for k in s2:
                if not k.find('a', {"class": "disabled"}):
                    subs1.append(k.find('td', {"width": "110"}).text)
                    subs.append(k.find('td', {"width": "60"}).text)
                    subs2.append(k.find('td', {"width": "109"}).text.strip(" "))

    for i in range(0, len(subs)):
        source1 = opener.open("https://www.codechef.com/viewplaintext/" + subs[i])
        soup1 = bs.BeautifulSoup(source1, 'html5lib')
        try:
            extnsion = languagedict[subs2[i]]
            if not handle == "":
                path = os.getcwd() + "/submissions/" + handle + "/" + subs2[i] + "/" + subs1[i] + subs[i] + extnsion
                if not os.path.exists(path):
                    try:
                        os.makedirs(os.path.dirname(path))
                    except OSError as exc:  # Guard against race condition
                        if exc.strerror == "Cannot create a file when that file already exists":
                            pass
                        else:
                            print(exc.strerror)
                with open(path, 'w') as submission:
                    submission.write(soup1.text)
            else:
                path = os.getcwd() + "/submissions/" + subs2[i] + "/" + subs1[i] + subs[i] + extnsion
                if not os.path.exists(path):
                    try:
                        os.makedirs(os.path.dirname(path))
                    except OSError as exc:  # Guard against race condition
                        if exc.strerror == "Cannot create a file when that file already exists":
                            pass
                        else:
                            print(exc.strerror)
                with open(path, 'w') as submission:
                    submission.write(soup1.text)

        except:
            extnsion = ".txt"
            if not handle == "":
                path = os.getcwd() + "/submissions/" + handle + "/" + subs1[i] + subs[i] + extnsion
                if not os.path.exists(path):
                    try:
                        os.makedirs(os.path.dirname(path))
                    except OSError as exc:  # Guard against race condition
                        if exc.strerror == "Cannot create a file when that file already exists":
                            pass
                        else:
                            print(exc.strerror)
                with open(path, 'w') as submission:
                    submission.write(soup1.text)
            else:
                path = os.getcwd() + "/submissions/" + subs1[i] + subs[i] + extnsion
                if not os.path.exists(path):
                    try:
                        os.makedirs(os.path.dirname(path))
                    except OSError as exc:  # Guard against race condition
                        if exc.strerror == "Cannot create a file when that file already exists":
                            pass
                        else:
                            print(exc.strerror)
                with open(path, 'w') as submission:
                    submission.write(soup1.text)
        print("fetched submission "+subs[i])
        if i==(len(subs)-1):
            print("done")
except:
    print("network error please try again")