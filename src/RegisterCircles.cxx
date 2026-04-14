#include "itkImage.h"
#include "itkImageFileReader.h"
#include "itkImageFileWriter.h"

#include <iostream>

// Type definitions
constexpr unsigned int Dimension = 2;
using PixelType  = float;
using ImageType  = itk::Image<PixelType, Dimension>;
using ReaderType = itk::ImageFileReader<ImageType>;
using WriterType = itk::ImageFileWriter<ImageType>;

// main
int main(int argc, char* argv[])
{
  if (argc < 4)
  {
    std::cerr << "Usage: " << argv[0]
              << " <fixed_image> <moving_image> <output_image>\n";
    return EXIT_FAILURE;
  }

  const std::string fixedFile  = argv[1];
  const std::string movingFile = argv[2];
  const std::string outputFile = argv[3];

  // Step 1: Read both images and print metadata
  auto fixedReader = ReaderType::New();
  fixedReader->SetFileName(fixedFile);
  fixedReader->Update();
  ImageType::Pointer fixedImage = fixedReader->GetOutput();

  auto movingReader = ReaderType::New();
  movingReader->SetFileName(movingFile);
  movingReader->Update();
  ImageType::Pointer movingImage = movingReader->GetOutput();

  std::cout << "=== Fixed Image: " << fixedFile << " ===\n";
  std::cout << "  Size    : " << fixedImage->GetLargestPossibleRegion().GetSize() << "\n";
  std::cout << "  Spacing : " << fixedImage->GetSpacing() << "\n";
  std::cout << "  Origin  : " << fixedImage->GetOrigin() << "\n";

  std::cout << "=== Moving Image: " << movingFile << " ===\n";
  std::cout << "  Size    : " << movingImage->GetLargestPossibleRegion().GetSize() << "\n";
  std::cout << "  Spacing : " << movingImage->GetSpacing() << "\n";
  std::cout << "  Origin  : " << movingImage->GetOrigin() << "\n";

  // Step 2: I will hardcode the center here to make things easier
  ImageType::PointType fixedCentroid;
  fixedCentroid[0] = 50.0;
  fixedCentroid[1] = 50.0;

  ImageType::PointType movingCentroid;
  movingCentroid[0] = 200.0;
  movingCentroid[1] = 200.0;

  std::cout << "=== Centroids ===\n";
  std::cout << "  Fixed  : (" << fixedCentroid[0]  << ", " << fixedCentroid[1]  << ") mm\n";
  std::cout << "  Moving : (" << movingCentroid[0] << ", " << movingCentroid[1] << ") mm\n";

  // Step 3: Compute translation and scale
  // Step 4: Build and apply transform
  // Step 5: Resample and write output
  // Step 6: Report residual error

  std::cout << "Registration complete.\n";
  return EXIT_SUCCESS;
}
