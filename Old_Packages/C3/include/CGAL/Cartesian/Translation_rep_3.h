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
// file          : include/CGAL/Cartesian/Translation_rep_3.h
// source        : include/CGAL/Cartesian/Translation_rep_3.h
// package       : C3
// revision      : $Revision$
// revision_date : $Date$
// author(s)     : Herve Bronnimann
//
// coordinator   : INRIA Sophia-Antipolis (Herve.Bronnimann@sophia.inria.fr)
//
// ==========================================================================

#ifndef CGAL_CARTESIAN_TRANSLATION_REP_3_H
#define CGAL_CARTESIAN_TRANSLATION_REP_3_H

CGAL_BEGIN_NAMESPACE

template < class R >
class Translation_repC3 : public Aff_transformation_rep_baseC3<R>
{
  friend class Aff_transformation_repC3<R>;
  friend class Scaling_repC3<R>;

public:
  typedef typename R::FT                                FT;
  typedef typename R::RT                                RT;
  typedef Aff_transformation_rep_baseC3<R>              Transformation_base_3;
  typedef Aff_transformation_repC3<R>                   Transformation_3;
  typedef Translation_repC3<R>                          Translation_3;
  typedef Scaling_repC3<R>                              Scaling_3;
  typedef typename Transformation_base_3::Point_3       Point_3;
  typedef typename Transformation_base_3::Vector_3      Vector_3;
  typedef typename Transformation_base_3::Direction_3   Direction_3;
  typedef typename Transformation_base_3::Aff_transformation_3
	                                                Aff_transformation_3;

  Translation_repC3() {}
  Translation_repC3(const Vector_3 &tv) : _translationvector(tv) {}
  virtual ~Translation_repC3() {}

  virtual Point_3     transform(const Point_3 &p) const
  {
    return p + _translationvector;
  }

  virtual Vector_3    transform(const Vector_3 &v) const
  {
    return v;
  }

  virtual Direction_3 transform(const Direction_3 &d) const
  {
    return d;
  }

  virtual Aff_transformation_3 operator*(const Transformation_base_3 &t) const
  {
    return t.compose(*this);
  }

  virtual Aff_transformation_3 compose(const Transformation_3 &t) const
  {
    return Aff_transformation_3(t.t11,
                                t.t12,
				t.t13,
				t.t11 * _translationvector.x()
				+ t.t12 * _translationvector.y()
				+ t.t13 * _translationvector.z() + t.t14,
				
				t.t21,
                                t.t22,
				t.t23,
				t.t21 * _translationvector.x()
				+ t.t22 * _translationvector.y()
				+ t.t23 * _translationvector.z() + t.t24,
				
				t.t31,
                                t.t32,
				t.t33,
				t.t31 * _translationvector.x()
				+ t.t32 * _translationvector.y()
				+ t.t33 * _translationvector.z() + t.t34);
  }

  virtual Aff_transformation_3 compose(const Translation_3 &t) const
  {
    return Aff_transformation_3(TRANSLATION,
                                _translationvector + t._translationvector);
  }

  virtual Aff_transformation_3 compose(const Scaling_3 &t) const
  {
    FT ft0(0);
    return Aff_transformation_3(t._scalefactor,
                                ft0,
				ft0,
				t._scalefactor * _translationvector.x(),
				
				ft0,
                                t._scalefactor,
				ft0,
				t._scalefactor * _translationvector.y(),
				
				ft0,
                                ft0,
				t._scalefactor,
				t._scalefactor * _translationvector.z());
  }

  virtual Aff_transformation_3 inverse() const
  {
    return Aff_transformation_3(TRANSLATION, - _translationvector);
  }

  virtual Aff_transformation_3 transpose() const
  {
    FT ft1(1), ft0(0);
    return Aff_transformation_3(TRANSLATION, _translationvector);
  }
  
  virtual bool is_even() const
  {
    return true;
  }

  virtual FT cartesian(int i, int j) const
  {
    if (j==i) return FT(1);
    if (j==3) return _translationvector[i];
    return FT(0);
  }

  virtual std::ostream &print(std::ostream &os) const
  {
    FT ft0(0), ft1(1);
    os << "Aff_transformationC3(VectorC3("<< _translationvector.x() << ","
       << _translationvector.y() << ","
       << _translationvector.z() << "))\n";
    return os;
  }

private:
  Vector_3   _translationvector;
};

CGAL_END_NAMESPACE

#endif // CGAL_CARTESIAN_TRANSLATION_REP_3_H
