#include <Router.h>

void Router::setRoute(std::string name, bool clear) {
  if (!history.empty()) {
    prevRouteName = getRoute().name;
  }

  if (clear)
    history.clear();
  history.push_back(routeMap.at(name));
}

Router::Router(std::map<std::string, Route> routes, History &restoredhistory,
               std::string defaultRoute) {
  for (auto r : routes) {
    routeMap[r.second.name] = r.second;
  }

  history = restoredhistory;

  if (history.size() == 0) {
    setRoute(defaultRoute);
  }
}

Route Router::getRoute() { return history.back(); }

bool Router::back() {
  if (history.size() < 2) {
    return false;
  }

  prevRouteName = getRoute().name;
  history.pop_back();
  return true;
}
