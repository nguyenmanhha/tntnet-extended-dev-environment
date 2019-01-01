////////////////////////////////////////////////////////////////////////
// src/app/views/index.cpp
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

log_define("component.src.app.views.index")

// <%pre>
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

static tnt::EcppComponentFactoryImpl<_component_> Factory("src/app/views/index");

static const char* rawData = "\010\000\000\000\370\002\000\000<h1>MyApp</h1>\n\n<p>Welcome to the MyApp application.</p"
  ">\n\n<p>This is a initial tntnet based project</p>\n\n<p>The next steps to take are:\n\n  <ul>\n    <li>Review <i>web"
  "main.ecpp</i> - it defines the overall layout of your web application</li>\n    <li>Edit <i>resources/MyApp.css</i></"
  "li>\n    <li>Add pages as needed into the <i>view</i> directory and <i>Makefile.am</i></li>\n    <li>Add per page pro"
  "cessing of user input of views in <i>controller</i> directory</li>\n    <li>Add static pages like images or js files "
  "into <i>resources</i> directory and <i>Makefile.am</i></li>\n    <li>If you want to use json, add handlers to <i>json"
  "</i> directory</li>\n    <li>If you need a database connection, read the howto or README.md how to do that</li>\n  </"
  "ul>\n</p>\n";

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
  log_trace("src/app/views/index " << qparam.getUrl());

  tnt::DataChunks data(rawData);

  // <%cpp>
  // <%include> src/app/models/index.ecpp
  // </%include>
  reply.out() << data[0]; // <h1>MyApp</h1>\n\n<p>Welcome to the MyApp application.</p>\n\n<p>This is a initial tntnet based project</p>\n\n<p>The next steps to take are:\n\n  <ul>\n    <li>Review <i>webmain.ecpp</i> - it defines the overall layout of your web application</li>\n    <li>Edit <i>resources/MyApp.css</i></li>\n    <li>Add pages as needed into the <i>view</i> directory and <i>Makefile.am</i></li>\n    <li>Add per page processing of user input of views in <i>controller</i> directory</li>\n    <li>Add static pages like images or js files into <i>resources</i> directory and <i>Makefile.am</i></li>\n    <li>If you want to use json, add handlers to <i>json</i> directory</li>\n    <li>If you need a database connection, read the howto or README.md how to do that</li>\n  </ul>\n</p>\n
  // <%/cpp>
  return DEFAULT;
}

} // namespace
