////////////////////////////////////////////////////////////////////////
// src/actionmain.cpp
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

log_define("component.src.actionmain")

// <%pre>
#line 1 "src/actionmain.ecpp"


#include "actionreply.h"
#include <cxxtools/json.h>
#include <tnt/httperror.h>


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

static tnt::EcppComponentFactoryImpl<_component_> Factory("src/actionmain");

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
  log_trace("src/actionmain " << qparam.getUrl());


#line 6 "./src/action.ecpp"
  typedef ActionReply actionReply_type;
  TNT_REQUEST_FILE_VAR(ActionReply, actionReply, ./src/action.ecpp, ());   // <%request> ActionReply actionReply
  _tnt_ignore_unused<actionReply_type>(actionReply);
  // <%cpp>
  // <%include> ./src/action.ecpp
  // </%include>
#line 9 "src/actionmain.ecpp"


// A action is a http request, which do not expect any output other than
// success or failure or notifications.

try
{
    // call the actual action component
    unsigned ret = callComp("action/" + request.getArg("next"), request, reply, qparam);

    log_debug("action <" << request.getArg("next") << "> http return code " << ret);
    if (ret > HTTP_OK)
        return ret;
}
catch (const tnt::HttpError& e)
{
    throw;
}
catch (const std::exception& e)
{
    log_warn(e.what());
    actionReply.setFailed(e.what());
}

reply.setContentType("application/json");
reply.out() << cxxtools::Json(actionReply);


  // <%/cpp>
  return DEFAULT;
}

} // namespace
