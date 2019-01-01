////////////////////////////////////////////////////////////////////////
// src/app/views/mypage.cpp
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

log_define("component.src.app.views.mypage")

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

static tnt::EcppComponentFactoryImpl<_component_> Factory("src/app/views/mypage");

static const char* rawData = "\010\000\000\000T\000\000\000<h1>hi</h1>\n\n<input type=\"button\" id=\"mybutton\" value="
  "\"click here\"></input>\n";

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
  log_trace("src/app/views/mypage " << qparam.getUrl());

  tnt::DataChunks data(rawData);

  // <%cpp>
  reply.out() << data[0]; // <h1>hi</h1>\n\n<input type="button" id="mybutton" value="click here"></input>\n
  // <%/cpp>
  return DEFAULT;
}

} // namespace
