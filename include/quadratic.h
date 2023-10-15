#ifndef QUADRATIC_H
#define QUADRATIC_H

#include "ros/service_traits.h"

namespace quadratic_solver
{

struct Quadratic
{
  typedef QuadraticRequest Request;
  typedef QuadraticResponse Response;
};

struct QuadraticRequest
{
  float64 a;
  float64 b;
  float64 c;

  typedef boost::shared_ptr<QuadraticRequest> Ptr;
  typedef boost::shared_ptr<QuadraticRequest const> ConstPtr;

};

struct QuadraticResponse
{
  float64 x1;
  float64 x2;

  typedef boost::shared_ptr<QuadraticResponse> Ptr;
  typedef boost::shared_ptr<QuadraticResponse const> ConstPtr;

};

template<typename ContainerAllocator>
struct Quadratic_
{
  typedef Quadratic_<ContainerAllocator> Type;

  Quadratic_()
    : request()
    , response()  {
    }
  Quadratic_(const ContainerAllocator& _alloc)
    : request(_alloc)
    , response(_alloc)  {
    }

   typedef typename ContainerAllocator::template rebind<QuadraticRequest>::other RequestAlloc;
   typedef typename ContainerAllocator::template rebind<QuadraticResponse>::other ResponseAlloc;

   typedef boost::shared_ptr<Quadratic_<ContainerAllocator> > Ptr;
   typedef boost::shared_ptr<Quadratic_<ContainerAllocator> const> ConstPtr;

   boost::shared_ptr<QuadraticRequest> request;
   boost::shared_ptr<QuadraticResponse> response;
}; // struct Quadratic_

typedef Quadratic_<std::allocator<void> > Quadratic;

typedef boost::shared_ptr<Quadratic> QuadraticPtr;
typedef boost::shared_ptr<Quadratic const> QuadraticConstPtr;

} // namespace quadratic_solver

namespace ros
{
namespace service_traits
{

template<>
struct MD5Sum< ::quadratic_solver::Quadratic > {
  static const char* value()
  {
    return "8d9c4a0f3c6a4b7f9c7b8e1d9a0f5e2a";
  }

  static const char* value(const ::quadratic_solver::Quadratic&) { return value(); }
};

template<>
struct DataType< ::quadratic_solver::Quadratic > {
  static const char* value()
  {
    return "quadratic_solver/Quadratic";
  }

  static const char* value(const ::quadratic_solver::Quadratic&) { return value(); }
};

template<>
struct MD5Sum< ::quadratic_solver::QuadraticRequest>
{
  static const char* value()
  {
    return MD5Sum< ::quadratic_solver::Quadratic >::value();
  }
  static const char* value(const ::quadratic_solver::QuadraticRequest&)
  {
    return value();
  }
};

template<>
struct DataType< ::quadratic_solver::QuadraticRequest>
{
  static const char* value()
  {
    return DataType< ::quadratic_solver::Quadratic >::value();
  }
  static const char* value(const ::quadratic_solver::QuadraticRequest&)
  {
    return value();
  }
};

template<>
struct MD5Sum< ::quadratic_solver::QuadraticResponse>
{
  static const char* value()
  {
    return MD5Sum< ::quadratic_solver::Quadratic >::value();
  }
  static const char* value(const ::quadratic_solver::QuadraticResponse&)
  {
    return value();
  }
};

template<>
struct DataType< ::quadratic_solver::QuadraticResponse>
{
  static const char* value()
  {
    return DataType< ::quadratic_solver::Quadratic >::value();
  }
  static const char* value(const ::quadratic_solver::QuadraticResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // QUADRATIC_H
