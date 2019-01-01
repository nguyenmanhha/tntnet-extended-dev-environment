////////////////////////////////////////////////////////////////////////
// src/app/actions/myaction.cpp
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

log_define("component.src.app.actions.myaction")

// <%pre>
#include <src/actionreply.h>
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

static tnt::EcppComponentFactoryImpl<_component_> Factory("src/app/actions/myaction");

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
  log_trace("src/app/actions/myaction " << qparam.getUrl());


#line 6 "./src/action.ecpp"
  typedef ActionReply actionReply_type;
  TNT_REQUEST_FILE_VAR(ActionReply, actionReply, ./src/action.ecpp, ());   // <%request> ActionReply actionReply
  _tnt_ignore_unused<actionReply_type>(actionReply);
  // <%cpp>
  // <%include> ./src/action.ecpp
  // </%include>
#line 2 "src/app/actions/myaction.ecpp"


// This is a example action, which just opens a notification in the browser.
actionReply.information("myaction activated");


  // <%/cpp>
  return DEFAULT;
}

} // namespace
