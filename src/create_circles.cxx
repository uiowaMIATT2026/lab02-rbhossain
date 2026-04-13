#include "itkImage.h"
#include "itkImageFileWriter.h"
#include "itkImageRegionIteratorWithIndex.h"
 
#include <iostream>
#include <cmath>
 
constexpr unsigned int Dimension = 2;
using PixelType = float;
using ImageType = itk::Image<PixelType, Dimension>;
 
ImageType::Pointer CreateCircleImage(
  double cx_mm, double cy_mm, double diameter_mm,
  unsigned int size_px, double spacing_mm)
{
  // Define image geometry
  ImageType::SizeType size;
  size[0] = size_px;
  size[1] = size_px;
 
  ImageType::IndexType start;
  start.Fill(0);
 
  ImageType::RegionType region;
  region.SetSize(size);
  region.SetIndex(start);
 
  ImageType::SpacingType spacing;
  spacing.Fill(spacing_mm);
 
  ImageType::PointType origin;
  origin.Fill(0.0);
 
  ImageType::DirectionType direction;
  direction.SetIdentity();
 
  // Define all the metadata
  ImageType::Pointer image = ImageType::New();
  image->SetRegions(region);
  image->SetSpacing(spacing);
  image->SetOrigin(origin);
  image->SetDirection(direction);
  image->Allocate();
  image->FillBuffer(0.0);
 
  // Draw the circles
  double radius_mm = diameter_mm / 2.0;
 
  itk::ImageRegionIteratorWithIndex<ImageType> it(image, region);
  for (it.GoToBegin(); !it.IsAtEnd(); ++it)
  {
    ImageType::IndexType idx = it.GetIndex();
 
    // Convert index to physical point
    ImageType::PointType pt;
    image->TransformIndexToPhysicalPoint(idx, pt);
 
    // Check if point is inside the circle
    double dx = pt[0] - cx_mm;
    double dy = pt[1] - cy_mm;
    double dist = std::sqrt(dx*dx + dy*dy);
 
    if (dist <= radius_mm)
      it.Set(255.0);
  }
 
  return image;
}
 
int main()
{
  using WriterType = itk::ImageFileWriter<ImageType>;
 
  // Create img1: 30mm diameter, center (50, 50) mm
  ImageType::Pointer img1 = CreateCircleImage(50.0, 50.0, 30.0, 300, 1.0);
  auto writer1 = WriterType::New();
  writer1->SetFileName("img1.mha");
  writer1->SetInput(img1);
  writer1->Update();
  std::cout << "Saved img1.mha\n";
 
  // Create img2: 60mm diameter, center (200, 200) mm
  ImageType::Pointer img2 = CreateCircleImage(200.0, 200.0, 60.0, 300, 1.0);
  auto writer2 = WriterType::New();
  writer2->SetFileName("img2.mha");
  writer2->SetInput(img2);
  writer2->Update();
  std::cout << "Saved img2.mha\n";
 
  return EXIT_SUCCESS;
}
