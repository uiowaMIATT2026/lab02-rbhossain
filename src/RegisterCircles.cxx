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
 
  std::cout << "Fixed image  : " << fixedFile  << "\n";
  std::cout << "Moving image : " << movingFile << "\n";
  std::cout << "Output image : " << outputFile << "\n";
 
  // Step 1: Read both images
  // Step 2: Compute centroids
  // Step 3: Compute translation and scale
  // Step 4: Build and apply transform
  // Step 5: Resample and write output
  // Step 6: Report residual error
 
  std::cout << "Registration complete.\n";
  return EXIT_SUCCESS;
}
 
