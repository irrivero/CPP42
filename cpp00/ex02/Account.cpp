/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 17:28:59 by irivero-          #+#    #+#             */
/*   Updated: 2024/07/01 14:58:07 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

// Initialization of static member var of the Account class
    int	Account::_nbAccounts = 0;
    int	Account::_totalAmount = 0;
    int	Account::_totalNbDeposits = 0;
    int	Account::_totalNbWithdrawals = 0;

// Private function to display the current timestamp
	void	Account::_displayTimestamp( void )
    {
        std::time_t t = std::time(0); // Get the current time
        std::tm *now = std::localtime(&t); // Convert to local time
        std::cout << "[" << now->tm_year + 1900 << now->tm_mon + 1 << now->tm_mday << "_" << now->tm_hour << now->tm_min << now->tm_sec << "] ";
    }
    
// static methods to get aggregated info of all accounts
	int	Account::getNbAccounts( void ) 
    {
        return (_nbAccounts);
    }
	int	Account::getTotalAmount( void )
    {
        return (_totalAmount);
    }
	int	Account::getNbDeposits( void )
    {
        return (_totalNbDeposits);   
    }
	int	Account::getNbWithdrawals( void )
    {
        return (_totalNbWithdrawals);
    }

// construct of the account class
    Account::Account( int initial_deposit )
    : _accountIndex(_nbAccounts), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
    {
        Account:: _nbAccounts++; // increment the account counter
        Account::_totalAmount += this->_amount; // increment the total amount by the initial deposit
        Account::_displayTimestamp();
        std::cout << "index:" << _accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
    }
// destructor
	Account::~Account( void )
    {
        Account::_displayTimestamp();
        std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
        Account::_nbAccounts--;
        Account::_totalAmount -= this->_amount;

    }

// method to make a deposit
    void	Account::makeDeposit( int deposit )
    {
        this->_nbDeposits++; // increment the accounts deposit counter
        this->_amount += deposit; // increment the account balance
        Account::_totalAmount += deposit; // increment th total amount in all accounts
        Account::_totalNbDeposits++; // increment the total deposit countr
        Account::_displayTimestamp();
        std::cout << "index:" << _accountIndex << ";p_amount:" << _amount - deposit << ";deposit:" << deposit << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
    }

// method to make a withdrawal
	bool	Account::makeWithdrawal( int withdrawal )
    {
        Account::_displayTimestamp();
        std::cout << "index:" << _accountIndex << ";p_amount:" << _amount; // print the previous balance
        if (this->_amount < withdrawal) // check if the withdrawal is possible
        {
            std::cout << ";withdrawal:refused" << std::endl;
            return (false);
        }
        this->_nbWithdrawals++; // increment the accounts withdrawal counter
        this->_amount -= withdrawal; // decrement the account balancce
        Account::_totalAmount -= withdrawal; // decrement the total amount in all accounts
        Account::_totalNbWithdrawals++; //increment the total withdrawal counter
        std::cout << ";withdrawal:" << withdrawal << ";amount:" << this->_amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
        return (true);
    }
    
   // method to check the account balance
	int		Account::checkAmount( void ) const
    {
        return (this->_amount);
    }
    
// method to display the account status
	void	Account::displayStatus( void ) const
    {
        Account::_displayTimestamp();
        std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
    }

// static method to display info of all accounts
	void	Account::displayAccountsInfos( void )
    {
        Account::_displayTimestamp();
        std::cout << "accounts:" << getNbAccounts() << ";total:" << getNbDeposits() << ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << ";" << std::endl;
    }
