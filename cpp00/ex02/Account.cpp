/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 17:28:59 by irivero-          #+#    #+#             */
/*   Updated: 2024/07/01 13:53:49 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

    int	Account::_nbAccounts = 0;
    int	Account::_totalAmount = 0;
    int	Account::_totalNbDeposits = 0;
    int	Account::_totalNbWithdrawals = 0;

	void	Account::_displayTimestamp( void )
    {
        std::time_t t = std::time(0);
        std::tm *now = std::localtime(&t);
        std::cout << "[" << now->tm_year + 1900 << now->tm_mon + 1 << now->tm_mday << "_" << now->tm_hour << now->tm_min << now->tm_sec << "] ";
    }
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

    Account::Account( int initial_deposit )
    : _accountIndex(_nbAccounts), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
    {
        Account:: _nbAccounts++;
        Account::_totalAmount += this->_amount;
        Account::_displayTimestamp();
        std::cout << "index:" << _accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
    }
    
	Account::~Account( void )
    {
        Account::_displayTimestamp();
        std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
        Account::_nbAccounts--;
        Account::_totalAmount -= this->_amount;
    }

    void	Account::makeDeposit( int deposit )
    {
        this->_nbDeposits++;
        this->_amount += deposit;
        Account::_totalAmount += deposit;
        Account::_totalNbDeposits++;
        Account::_displayTimestamp();
        std::cout << "index:" << _accountIndex << ";p_amount:" << _amount - deposit << ";deposit:" << deposit << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
    }
	bool	Account::makeWithdrawal( int withdrawal )
    {
        Account::_displayTimestamp();
        std::cout << "index:" << _accountIndex << ";p_amount:" << _amount;
        if (this->_amount < withdrawal)
        {
            std::cout << ";withdrawal:refused" << std::endl;
            return (false);
        }
        this->_nbWithdrawals++;
        this->_amount -= withdrawal;
        Account::_totalAmount -= withdrawal;
        Account::_totalNbWithdrawals++;
        std::cout << ";withdrawal:" << withdrawal << ";amount:" << this->_amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
        return (true);
    }
	int		Account::checkAmount( void ) const
    {
        return (this->_amount);
    }
	void	Account::displayStatus( void ) const
    {
        Account::_displayTimestamp();
        std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
    }
    
	void	Account::displayAccountsInfos( void )
    {
        Account::_displayTimestamp();
        std::cout << "accounts:" << getNbAccounts() << ";total:" << getNbDeposits() << ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << ";" << std::endl;
    }