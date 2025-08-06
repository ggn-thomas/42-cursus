/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 12:54:03 by thomas            #+#    #+#             */
/*   Updated: 2025/08/06 14:05:37 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 137, 145), target("default") {
    std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 137, 145), target(target){
    std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &cpy) : AForm(cpy), target(cpy.target){
    std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &shrubberyCreationForm) {
    std::cout << "ShrubberyCreationForm copy assignement operator called" << std::endl;
    if (this != &shrubberyCreationForm)
        this->target = shrubberyCreationForm.target;
    return (*this);
}

void ShrubberyCreationForm::executeAction() const {
    std::string fileName;
    std::string asciiTrees;

    asciiTrees ="    /\\\n"
                "   /  \\\n"
                "  /    \\\n"
                " /______\\\n"
                "    ||\n";
    fileName = this->target + "_shrubbery";
    std::ofstream newFile(fileName.c_str());
    if (!newFile.is_open())
    {
        std::cout << "Error: cannot create " << fileName << std::endl;
        return ;
    }
    for (int i = 0 ; i < 5 ; i++){
        newFile << asciiTrees;
        newFile << "\n";
    }
    newFile.close();
}