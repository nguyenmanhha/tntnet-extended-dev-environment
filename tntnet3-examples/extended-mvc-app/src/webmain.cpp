////////////////////////////////////////////////////////////////////////
// src/webmain.cpp
// generated with ecppc
//

#include <tnt/ecpp.h>
#include <tnt/httprequest.h>
#include <tnt/httpreply.h>
#include <tnt/httpheader.h>
#include <tnt/http.h>
#include <tnt/data.h>
#include <tnt/componentfactory.h>
#include <cxxtools/log.h>
#include <stdexcept>

log_define("component.src.webmain")

// <%pre>
#line 1 "src/webmain.ecpp"

#include <cxxtools/json.h>

#line 1 "./src/session.ecpp"


    // Structure, which contains session specific variables
    struct Session
    {
    };


#include <src/noty.h>
#include <src/configuration.h>
// </%pre>

namespace
{
class _component_ : public tnt::EcppComponent
{
    _component_& main()  { return *this; }

  protected:
    ~_component_();

  public:
    _component_(const tnt::Compident& ci, const tnt::Urlmapper& um, tnt::Comploader& cl);

    unsigned operator() (tnt::HttpRequest& request, tnt::HttpReply& reply, tnt::QueryParams& qparam);
};

static tnt::EcppComponentFactoryImpl<_component_> Factory("src/webmain");

static const char* rawData = "\030\000\000\000\030\001\000\000\016\002\000\000^\002\000\000\263\003\000\000\321\003\000"
  "\000<!DOCTYPE html>\n<html>\n  <head>\n    <title>tntnet application MyApp</title>\n    <meta charset=\"UTF-8\">\n   "
  " <meta name=\"description\" content=\"MyApp application\">\n    <link rel=\"stylesheet\" href=\"/MyApp.css\" type=\"t"
  "ext/css\">\n    <link rel=\"stylesheet\" href=\".css\" type=\"text/css\">\n    <script src=\"/js/jquery-2.1.4.min.js"
  "\"></script>\n    <script src=\"/js/noty/packaged/jquery.noty.packaged.min.js\"></script>\n    <script src=\"/js/tntn"
  "et.js\"></script>\n    <script src=\"/MyApp.js\"></script>\n    <script src=\".js\"></script>\n    <script>\n      $("
  "function() {\n          processNotifications()\n      });\n    </script>\n  </head>\n  <body>\n    <div id=\"header\""
  ">\n      <span id=\"title\">MyApp application</span>\n    </div>\n\n    <div id=\"menu\">\n      <ul class=\"nav\">\n"
  "        <li class=\"navitem\"><a href=\"/\">Home</a></li>\n        <li class=\"navitem\"><a href=\"/mypage\">My page<"
  "/a></li>\n      </ul>\n    </div>\n\n    <div id=\"content\">\n       \n    </div>\n  </body>\n</html>\n";

// <%shared>
// </%shared>

// <%config>
// </%config>

#define SET_LANG(lang) \
     do \
     { \
       request.setLang(lang); \
       reply.setLocale(request.getLocale()); \
     } while (false)

_component_::_component_(const tnt::Compident& ci, const tnt::Urlmapper& um, tnt::Comploader& cl)
  : EcppComponent(ci, um, cl)
{
  // <%init>
  // </%init>
}

_component_::~_component_()
{
  // <%cleanup>
  // </%cleanup>
}

template <typename T>
inline void _tnt_ignore_unused(const T&) { }

unsigned _component_::operator() (tnt::HttpRequest& request, tnt::HttpReply& reply, tnt::QueryParams& qparam)
{
  log_trace("src/webmain " << qparam.getUrl());

  tnt::DataChunks data(rawData);

#line 12 "./src/session.ecpp"
  typedef Session session_type;
  TNT_SESSION_FILE_VAR(Session, session, ./src/session.ecpp, ());   // <%session> Session session
  _tnt_ignore_unused<session_type>(session);
#line 26 "./src/session.ecpp"
  typedef Noty noty_type;
  TNT_REQUEST_FILE_VAR(Noty, noty, ./src/session.ecpp, ());   // <%request> Noty noty
  _tnt_ignore_unused<noty_type>(noty);
  // <%cpp>
#line 4 "src/webmain.ecpp"

std::string maincomp = request.getArg("next");

  // <%include> ./src/session.ecpp
#line 15 "./src/session.ecpp"


    // Make configuration easily accessable
    const Configuration& configuration = Configuration::it();


  // </%include>
  reply.out() << data[0]; // <!DOCTYPE html>\n<html>\n  <head>\n    <title>tntnet application MyApp</title>\n    <meta charset="UTF-8">\n    <meta name="description" content="MyApp application">\n    <link rel="stylesheet" href="/MyApp.css" type="text/css">\n    <link rel="stylesheet" href="
#line 15 "src/webmain.ecpp"
  reply.sout() << ( maincomp );
  reply.out() << data[1]; // .css" type="text/css">\n    <script src="/js/jquery-2.1.4.min.js"></script>\n    <script src="/js/noty/packaged/jquery.noty.packaged.min.js"></script>\n    <script src="/js/tntnet.js"></script>\n    <script src="/MyApp.js"></script>\n    <script src="
#line 20 "src/webmain.ecpp"
  reply.sout() << ( maincomp );
  reply.out() << data[2]; // .js"></script>\n    <script>\n      $(function() {\n          processNotifications(
#line 23 "src/webmain.ecpp"
  reply.out() << ( cxxtools::Json(noty) );
  reply.out() << data[3]; // )\n      });\n    </script>\n  </head>\n  <body>\n    <div id="header">\n      <span id="title">MyApp application</span>\n    </div>\n\n    <div id="menu">\n      <ul class="nav">\n        <li class="navitem"><a href="/">Home</a></li>\n        <li class="navitem"><a href="/mypage">My page</a></li>\n      </ul>\n    </div>\n\n    <div id="content">\n       
  // <& ("src/app/views/" + maincomp) ...
  { 
#line 40 "src/webmain.ecpp"
    tnt::QueryParams _tnt_cq0(qparam);
#line 40 "src/webmain.ecpp"
    callComp(("src/app/views/" + maincomp), request, reply, _tnt_cq0);
    // &>
  }
  reply.out() << data[4]; // \n    </div>\n  </body>\n</html>\n
  // <%/cpp>
  return DEFAULT;
}

} // namespace
