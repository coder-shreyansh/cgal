// ==========================================================================
//
// Copyright (c) 1998, 1999 The CGAL Consortium
//
// This software and related documentation is part of an INTERNAL release
// of the Computational Geometry Algorithms Library (CGAL). It is not
// intended for general use.
//
// --------------------------------------------------------------------------
//
// release       :
// release_date  :
//
// file          : include/CGAL/Cartesian/distance_computations_3.h
// source        : include/CGAL/Cartesian/distance_computations_3.h
// package       : C3
// revision      : $Revision$
// revision_date : $Date$
// author(s)     : Herve Bronnimann
//
// coordinator   : INRIA Sophia-Antipolis (Herve.Bronnimann@sophia.inria.fr)
//
// ==========================================================================

#ifndef CGAL_CARTESIAN_DISTANCE_COMPUTATIONS_3_H
#define CGAL_CARTESIAN_DISTANCE_COMPUTATIONS_3_H

#include <CGAL/Cartesian/redefine_names_3.h>
#include <CGAL/Cartesian/Point_3.h>
#include <CGAL/Cartesian/Vector_3.h>
#include <CGAL/Cartesian/Plane_3.h>
#include <CGAL/constructions/kernel_ftC3.h>

CGAL_BEGIN_NAMESPACE

template < class R >
inline
typename R::FT
squared_distance(const PointC3<R CGAL_CTAG> &p,
                 const PointC3<R CGAL_CTAG> &q)
{
  return squared_distanceC3(p.x(),p.y(),p.z(),q.x(),q.y(),q.z());
}

template < class R >
inline
typename R::FT
scaled_distance_to_plane(const PlaneC3<R CGAL_CTAG> &h,
                         const PointC3<R CGAL_CTAG> &p)
{
  return scaled_distance_to_planeC3(h.a(),h.b(),h.c(),h.d(),
                                    p.x(),p.y(),p.z());
}

template < class R >
inline
typename R::FT
scaled_distance_to_plane(const PointC3<R CGAL_CTAG> &hp,
                         const PointC3<R CGAL_CTAG> &hq,
                         const PointC3<R CGAL_CTAG> &hr,
                         const PointC3<R CGAL_CTAG> &p)
{
  return scaled_distance_to_planeC3(hp.x(),hp.y(),hp.z(),
                                    hq.x(),hq.y(),hq.z(),
                                    hr.x(),hr.y(),hr.z(),
                                    p.x(),p.y(),p.z());
}

CGAL_END_NAMESPACE

#endif // CGAL_CARTESIAN_DISTANCE_COMPUTATIONS_3_H
